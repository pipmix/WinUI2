#include "ChildWindow.h"



LRESULT CALLBACK ChildWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

		case WM_RBUTTONUP:
			RightClick(hWnd, lParam);
			break;


	default:
		break;

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CreateChildWindow(WinDat & wd){


	//settings.backgroundColor = RGB(51, 153, 255);
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ChildWindowProc;
	wcex.hbrBackground = CreateSolidBrush(RGB(51, 153, 255));
	wcex.lpszClassName = wd._className;




	RegisterClassEx(&wcex);

	wd._handle = CreateWindowEx(0, wd._className, NULL, wd._style, wd._x, wd._y, wd._w, wd._h, wd._parent, 0, NULL, NULL);

	ShowWindow(wd._handle, 1);
	UpdateWindow(wd._handle);

}

