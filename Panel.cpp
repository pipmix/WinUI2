#include "Panel.h"

Panel::Panel(HWND parentHandle, PANEL_TYPE pt, PANEL_ORIENTATION po, WCHAR* name) : _parentHwnd(parentHandle), _panelType(pt), _panelOrientation(po), _className(name){

	Init();
}

Panel::~Panel()
{
}

void Panel::Init(){


	WNDCLASSEX	wcex;
	wcex.cbSize = sizeof(wcex);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(0);
	wcex.hIcon = 0;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = _className;
	wcex.hIconSm = 0;

	RegisterClassEx(&wcex);

	switch (_panelType) {
		case TREEVIEW:

			break;
		case LISTVIEW:

			break;
	}

	_hwnd = CreateWindowEx(0,
		_className, NULL,
		WS_VSCROLL | WS_HSCROLL | WS_CHILD | WS_VISIBLE | WS_BORDER,
		0, 0, 0, 0,
		_parentHwnd, 0, GetModuleHandle(0), 0);

}


LRESULT CALLBACK Panel::MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {



	}

}
