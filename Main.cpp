
#define WIN32_LEAN_AND_MEAN	
#include "MainWindow.h"
#include "ChildWindow.h"
#include "ControlWindow.h"
#include "TimeLineControl.h"
#include "Button.h"

Settings settings;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	WinDat mainWindow{ nullptr, nullptr, hInstance, nCmdShow, 100, 100, 1000, 800, L"MainWindowClass", L"This Title", 0, WS_OVERLAPPEDWINDOW };
	CreateMainWindow(mainWindow);

	settings.Init(mainWindow._handle, hInstance);
	

	InitTimelineControl();
	InitSplitControl();
	Button but;
	but.Register();




	

	SplitWindow* mainSplit = new SplitWindow(mainWindow._handle, SplitType::HORIZONTAL, 50);
	SplitWindow* bottomSplit = mainSplit->SplitB(SplitType::HORIZONTAL, 600);
	SplitWindow* midLeftSplit = bottomSplit->SplitA(SplitType::VERTICAL, 200);
	SplitWindow* midRightSplit = midLeftSplit->SplitB(SplitType::HORIZONTAL, 200);

	WinDat topPanel{ nullptr, mainWindow._handle, hInstance, 5, 0, 0, 0, 0, L"topPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	WinDat bottomPanel{ nullptr, mainWindow._handle, hInstance, 6, 0, 0, 0, 0, L"bottomPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	//WinDat midLeft{ nullptr, mainWindow._handle, hInstance, 7, 0, 0, mainWindow._w, divTopLocY, L"midLeftPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	WinDat midLeft{ nullptr, mainWindow._handle, hInstance, 7, 0, 0, 0, 0, L"midLeftPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	WinDat midRightTop{ nullptr, mainWindow._handle, hInstance, 8, 0, 0, 0, 0, WC_TREEVIEW,  L"", 0, WS_CHILD | WS_VISIBLE | TVS_FULLROWSELECT };
	WinDat midRightBottom{ nullptr, mainWindow._handle, hInstance, 9, 0, 0, 0, 0, L"midRightBottomPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };

	//WinDat splitTest{ nullptr, mainWindow._handle, hInstance, 9, 0, 0, 0, 0, L"SplitClass",  L"", 0, WS_CHILD | WS_VISIBLE };

	mainSplit->AttachA(&topPanel);
	bottomSplit->AttachB(&bottomPanel);
	midLeftSplit->AttachA(&midLeft);
	midRightSplit->AttachA(&midRightTop);
	midRightSplit->AttachB(&midRightBottom);




	CreateChildWindow(topPanel);
	CreateChildWindow(bottomPanel);
	CreateChildWindow(midLeft);
	CreateControlWindow(midRightTop);
	CreateChildWindow(midRightBottom);

	mainSplit->CreateSplitPane();
	bottomSplit->CreateSplitPane();
	midLeftSplit->CreateSplitPane();
	midRightSplit->CreateSplitPane();

	
	Button but01, but02, but03;
	int tempW = 100;
	int tempH = 50;
	int space = 5;

	int startX = 200;
	int startH = 200;
	but01.Create(mainWindow._handle, L"CLickMe", startX, startH, tempW, tempH);

	startX += (tempW + space);
	but02.Create(mainWindow._handle, L"CLick22", startX, startH, tempW, tempH);
	startX += (tempW + space);
	but03.Create(mainWindow._handle, L"Clicss333", startX, startH, tempW, tempH);
	startX += (tempW + space);
	//HWND tl = CreateTimeLineControl(mainWindow._handle);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

