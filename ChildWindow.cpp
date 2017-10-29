#include "ChildWindow.h"



LRESULT CALLBACK ChildWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {





	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CreateChildWindow(WinDat & wd){


	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ChildWindowProc;
	wcex.hbrBackground = GetSysColorBrush(COLOR_3DHIGHLIGHT);
	wcex.lpszClassName = wd._className;

	switch (wd._var) {
	case 5:
		wcex.hbrBackground = GetSysColorBrush(COLOR_MENUHILIGHT);
		break;
	case 6:
		wcex.hbrBackground = GetSysColorBrush(COLOR_MENUHILIGHT);
		break;
	case 7:
		wcex.hbrBackground = GetSysColorBrush(COLOR_MENUHILIGHT);
		break;
	case 8:
		wcex.hbrBackground = GetSysColorBrush(COLOR_MENUHILIGHT);
		break;
	case 9:
		wcex.hbrBackground = GetSysColorBrush(COLOR_MENUHILIGHT);
		break;
	}


	RegisterClassEx(&wcex);

	wd._handle = CreateWindowEx(0, wd._className, NULL, wd._style, wd._x, wd._y, wd._w, wd._h, wd._parent, 0, NULL, NULL);

	ShowWindow(wd._handle, 1);
	UpdateWindow(wd._handle);

}

