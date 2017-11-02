#include "SplitControl.h"



void InitSplitControl() {

	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbWndExtra = sizeof(SplitControlParam*);
	wcex.lpfnWndProc = SplitWindowProc;
	wcex.hbrBackground = settings.splitBackgroundBrush;//GetSysColorBrush(COLOR_DESKTOP);
	wcex.lpszClassName = L"SplitClass";
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hInstance = settings.hInstance;
	RegisterClassEx(&wcex);
}

SplitControlParam* GetSplit(HWND h) {
	SplitControlParam* split = (SplitControlParam*)GetWindowLong(h, 0);
	return split;
}

void SetSplit(HWND h, SplitControlParam* param) {
	SetWindowLong(h, 0, (LONG)param);
}

void CreateSplitControl(WinDat& wd) {



	wd._handle = CreateWindowEx(0, wd._className, NULL, wd._style, wd._x, wd._y, wd._w, wd._h, wd._parent, 0, NULL, NULL);

	ShowWindow(wd._handle, 1);
	UpdateWindow(wd._handle);
}

LRESULT SplitPaint(SplitControlParam* t, WPARAM wp, LPARAM lp) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;



	hdc = BeginPaint(t->_hWnd, &ps);

	SetBkColor(hdc, t->_backgroundColor);

	GetClientRect(t->_hWnd, &rect);

	
	EndPaint(t->_hWnd, &ps);
	return 0;

}

LRESULT SplitLeftClick(SplitControlParam* t, WPARAM wp, LPARAM lp) {
	COLORREF color = RGB(rand() % 256, rand() % 256, rand() % 256);
	t->_backgroundColor = color;


	InvalidateRect(t->_hWnd, 0, 0);
	UpdateWindow(t->_hWnd);
	return 0;

}


LRESULT CALLBACK SplitWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	SplitControlParam* p = (SplitControlParam*)GetWindowLong(hWnd, 0);
	switch (message) {
	case WM_NCCREATE:
		p = (SplitControlParam*)malloc(sizeof(SplitControlParam));

		p->_backgroundColor = GetSysColor(COLOR_WINDOWTEXT);

		p->_hWnd = hWnd;
		p->_cursor = settings.verticalSplit;
		SetWindowText(hWnd, ((CREATESTRUCT*)lParam)->lpszName);
		SetSplit(hWnd, p);
		return 1;
	case WM_NCDESTROY:
		free(p);
		break;

	case WM_SETCURSOR:
		SetCursor(settings.verticalSplit);
		return 1;

	default:
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}















SplitControl::SplitControl(SplitControlParam* param) {

	_param = param;
}
SplitControl::~SplitControl() {
}

void SplitControl::SetData(SplitControlParam* param) {
	_param = param;
}
SplitControlParam* SplitControl::GetData() {
	return _param;
}

bool SplitControl::Init() {
	//tlc = (TimeLineControl*)malloc(sizeof(TimeLineControl));
	return 1;
}


bool SplitControl::MouseMoveMessage() {



	return 1;
}
bool SplitControl::LeftButtonDownMessage() {

	return 1;
}
bool SplitControl::LeftButtonUpMessage() {

	return 1;
}
bool SplitControl::PaintMessage() {

	return 1;
}




LRESULT CALLBACK SplitControl::SplitControlProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	SplitControl* control = (SplitControl*)GetWindowLong(hWnd, 0);

	switch (message) {
		case WM_NCCREATE: 
			return control->Init();

		case WM_NCDESTROY: 
			free(control);
			break;

		case WM_SETCURSOR:
			SetCursor(settings.verticalSplit);
			return 1;
		case WM_LBUTTONDOWN:
			return control->LeftButtonDownMessage();
		case WM_MOUSEMOVE:
			return control->MouseMoveMessage();

		case WM_LBUTTONUP:
			return control->LeftButtonUpMessage();
		default:
			break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
