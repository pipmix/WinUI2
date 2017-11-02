#include "TimeLineControl.h"

typedef struct {
	COLORREF _frontColor;
	COLORREF _backColor;
	HFONT _hFont;
	HWND _hWnd;
} TimeLineControl;

void InitTimelineControl() {

	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbWndExtra = sizeof(TimeLineControl*);
	wcex.lpfnWndProc = TimeLineWindowProc;
	wcex.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
	wcex.lpszClassName = L"TimeLineClass";
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hInstance = GetModuleHandle(0);
	RegisterClassEx(&wcex);
}

TimeLineControl* GetTimeLine(HWND h) {
	TimeLineControl* timeLine = (TimeLineControl* )GetWindowLong(h, 0);
	return timeLine;
}

void SetTimeLine(HWND h, TimeLineControl* t) {
	SetWindowLong(h, 0, (LONG)t);
}

HWND CreateTimeLineControl(HWND p) {

	HWND handle = CreateWindowEx(0 , L"TimeLineClass", L"TimeLineWindow", WS_VISIBLE | WS_CHILD, 0, 0, 100, 100, p, 0, GetModuleHandle(0), 0);
	return handle;

}

LRESULT TimeLinePaint(TimeLineControl* t, WPARAM wp, LPARAM lp) {
	HDC hdc;
	PAINTSTRUCT ps;
	HANDLE oldfont;
	TCHAR text [] = L"This is test, going here and there and away from it all this time";
	RECT rect;



	hdc = BeginPaint(t->_hWnd, &ps);
	oldfont = SelectObject(hdc, t->_hFont);
	SetTextColor(hdc, t->_frontColor);
	SetBkColor(hdc, t->_backColor);
	////GetWindowText(t->_hWnd, text, sizeof(text));
	GetClientRect(t->_hWnd, &rect);
	//GetTextExtentPoint32(hdc, text, lstrlen(text), &sz);
	ExtTextOut(hdc, 5, 25, ETO_OPAQUE, &rect, text, lstrlen(text), 0);
	SelectObject(hdc, oldfont);
	EndPaint(t->_hWnd, &ps);
	return 0;
	
}

LRESULT TimeLineLeftClick(TimeLineControl* t, WPARAM wp, LPARAM lp) {
	COLORREF color = RGB(rand() % 256, rand() % 256, rand() % 256);
	t->_frontColor = color;
	t->_backColor = ((~color) & 0x00ffffff);

	InvalidateRect(t->_hWnd, 0, 0);
	UpdateWindow(t->_hWnd);
	return 0;

}


LRESULT CALLBACK TimeLineWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	TimeLineControl* tlc = (TimeLineControl* )GetWindowLong(hWnd, 0);
	switch (message) {
	case WM_NCCREATE:
		tlc = (TimeLineControl*)malloc(sizeof(TimeLineControl));
		tlc->_frontColor = GetSysColor(COLOR_WINDOWTEXT);
		tlc->_backColor = GetSysColor(COLOR_WINDOWTEXT);
		tlc->_hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		tlc->_hWnd = hWnd;

		SetWindowText(hWnd, ((CREATESTRUCT*)lParam)->lpszName);
		SetTimeLine(hWnd, tlc);
		return 1;
	case WM_NCDESTROY:
		free(tlc);
		break;
	case WM_PAINT:
		return TimeLinePaint(tlc, wParam, lParam);
	case WM_LBUTTONDOWN:
		return TimeLineLeftClick(tlc, wParam, lParam);
	case WM_ERASEBKGND:
		return 1;
	case WM_MOUSEACTIVATE:
		SetFocus(hWnd);
		return MA_ACTIVATE;
	case WM_SETFONT:
		tlc->_hFont = (HFONT)wParam;
		return 0;
	default:
			break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

