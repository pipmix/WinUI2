#include "Button.h"

Button::Button()
{
	winProp = { 0 };
}


LRESULT CALLBACK Button::ButtonWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_RBUTTONUP:
		
		break;


	default:
		break;

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}


void Button::Register() {
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ButtonWindowProc;
	wcex.hbrBackground = settings.colors.Button_Background;
	wcex.lpszClassName = L"BUTTONCONTROL";
	RegisterClassEx(&wcex);

}
void Button::Create(HWND p, LPCWSTR str, int x, int y, int w, int h){
	winProp.parent = p;
	winProp.className = L"BUTTONCONTROL";
	winProp.windowName = str;
	winProp.x = x;
	winProp.y = y;
	winProp.w = w;
	winProp.h = h;
	winProp.styles = WS_CHILD | WS_VISIBLE;
	winProp.handle = CreateWindowEx(0, winProp.className, NULL, winProp.styles, winProp.x, winProp.y, winProp.w, winProp.h, winProp.parent, 0, NULL, NULL);

	ShowWindow(winProp.handle, 1);
	UpdateWindow(winProp.handle);
}

