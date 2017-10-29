#include "MainWindow.h"

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_CREATE:
		break;
	case WM_SIZE:
		
		break;
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