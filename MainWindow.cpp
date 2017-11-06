#include "MainWindow.h"



void CreateMenu(HWND hWnd) {


	HMENU menuBar = AddMenuBar(hWnd);
	HMENU fileCategory = AddMenuCategory(menuBar, L"File");
	HMENU editCategory = AddMenuCategory(menuBar, L"Edit");
	

	AddMenuItem(fileCategory, 1, L"New");
	AddMenuItem(fileCategory, 2, L"Open");
	AddMenuItem(fileCategory, 3, L"Close");

	AddMenuItem(editCategory, 4, L"Copy");
	AddMenuItem(editCategory, 5, L"Paste");
	AddMenuItem(editCategory, 6, L"Cut");
	AddMenuSeperator(editCategory);
	AddMenuItem(editCategory, 7, L"Select");
	AddMenuItem(editCategory, 8, L"Select All");
	AddMenuSeperator(editCategory);
	AddMenuItem(editCategory, 9, L"Undo");
	AddMenuItem(editCategory, 10, L"Redo");
	AddMenuSeperator(editCategory);
	HMENU prefSubCategory = AddMenuSubCategory(editCategory, L"Prefrences");
	AddMenuItem(prefSubCategory, 9, L"Open Prefrences");
	AddMenuItem(prefSubCategory, 9, L"Delete Prefrences");
}


bool MsgCommand(HWND hWnd, WPARAM wParam) {

	switch (LOWORD(wParam)) {

	default:;
			break;

	}
	return 1;
}








LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {



	case WM_CREATE:

		CreateMenu(hWnd);

		break;
	case WM_SIZE: {
		//WinDat* temp = mainSplit->GetWinDatA();
		//if (temp != nullptr) {
		//	RECT clientRect;
		//	GetClientRect(temp->_handle, &clientRect);
		//}



		//MoveWindow(temp->_handle, mainSplit->_x, mainSplit->_y, clientRect.right, temp->_h, 1);
		}
		break;



	case WM_COMMAND:
		return MsgCommand(hWnd, wParam);
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
}



void CreateMainWindow(WinDat& wd) {


	WNDCLASSEX wcex = { 0 };

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW;
	wcex.lpfnWndProc = MainWindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = wd._hInstance;
	wcex.hIcon = (HICON)LoadImage(NULL, NULL, IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = GetSysColorBrush(COLOR_GRAYTEXT);//  (HBRUSH)(COLOR_GRAYTEXT);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = wd._className;
	wcex.hIconSm = (HICON)LoadImage(NULL, NULL, IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);

	RegisterClassEx(&wcex);

	wd._handle = CreateWindowEx(wd._exStyle, wd._className, wd._windowName, wd._style, wd._x, wd._y, wd._w, wd._h, NULL, NULL, wd._hInstance, NULL);

	ShowWindow(wd._handle, wd._var);
	UpdateWindow(wd._handle);

	// Set client to actual diminsion
	RECT clientRect;
	GetClientRect(wd._handle, &clientRect);
	int offsetX = wd._w - (clientRect.right - clientRect.left);
	int offsetY = wd._h - (clientRect.bottom - clientRect.top);
	SetWindowPos(wd._handle, NULL, wd._x, wd._y, wd._w + offsetX, wd._h + offsetY, NULL);
	UpdateWindow(wd._handle);

}