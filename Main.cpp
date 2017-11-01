
#define WIN32_LEAN_AND_MEAN	
#include "MainWindow.h"
#include "ChildWindow.h"
#include "ControlWindow.h"
#include "TimeLineControl.h"


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	HINSTANCE hInst = hInstance;


	WindowSettings* settings = new WindowSettings();
	settings->backgroundColor = (RGB(51, 153, 255));

	
	//settings->textColor = RGB(0, 0, 0);
	//settings->highlightColor = RGB(255, 128, 64);
	//settings->font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

	int divSize = 2;
	int divTopLocY = 25;
	int divLeftLocX = 200;

	WinDat mainWindow{ nullptr, nullptr, hInstance, nCmdShow, 100, 100, 1000, 800, L"MainWindowClass", L"This Title", 0, WS_OVERLAPPEDWINDOW };
	CreateMainWindow(mainWindow);


	//WinDat topPanel{ nullptr, mainWindow._handle, hInstance, nCmdShow, 0, 0, mainWindow._w, divTopLocY, L"topPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	//WinDat leftPanel{ nullptr, mainWindow._handle, hInstance, nCmdShow, 0, divTopLocY + divSize, divLeftLocX, mainWindow._h - (divTopLocY + divSize), L"leftPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };
	//WinDat contentPanel{ nullptr, mainWindow._handle, hInstance, nCmdShow, divLeftLocX + divSize, divTopLocY + divSize, mainWindow._w - (divLeftLocX + divSize) , mainWindow._h - (divTopLocY + divSize), L"contentPaneWindowClass",  L"", 0, WS_CHILD | WS_VISIBLE };

	//CreateChildWindow(topPanel);
	//CreateChildWindow(leftPanel);
	//CreateChildWindow(contentPanel);

	

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


	TV_INSERTSTRUCT tvins;

	tvins = { 0 };

	tvins.hInsertAfter = TVI_ROOT;
	tvins.item.mask = TVIF_TEXT;
	tvins.item.pszText = L"Root";
	tvins.item.cchTextMax = 10;

	HTREEITEM hRoot = TreeView_InsertItem(midRightTop._handle, &tvins);

	InitTimelineControl();
	HWND tl = CreateTimeLineControl(mainWindow._handle);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

