#include "SplitWindow.h"

SplitWindow::SplitWindow(HWND h, SplitType t, int loc){

	_parentHandle = h;
	RECT clientRect;
	GetClientRect(_parentHandle, &clientRect);
	_x = clientRect.left;
	_y = clientRect.top;
	_w =  (clientRect.right - clientRect.left);
	_h = (clientRect.bottom - clientRect.top);
	_level = 0;

	SetType(t, loc);
}

SplitWindow::SplitWindow(SplitType t, int loc, int level, HWND parent) {
	_level = level;
	level++;
	_parentHandle = parent;

	SetType(t, loc);

}

void SplitWindow::SetType(SplitType t, int loc) {
	_divSize = 3;
	_type = t;
	if (_type == SplitType::HORIZONTAL)_divLocY = loc;
	else if (_type == SplitType::VERTICAL)_divLocX = loc;

	

}

void SplitWindow::CreateSplitPane() {

	if (_type == SplitType::HORIZONTAL)
	_split = CreateWindowEx(0, L"SplitClass", NULL, WS_CHILD | WS_VISIBLE, _x, _y + _divLocY, _w, _divSize, settings.hWnd, 0, NULL, NULL);
	else if (_type == SplitType::VERTICAL) _split = CreateWindowEx(0, L"SplitClass", NULL, WS_CHILD | WS_VISIBLE, _x + _divLocX, _y, _divSize, _h, settings.hWnd, 0, NULL, NULL);

	ShowWindow(_split, 1);
	UpdateWindow(_split);

	//nullptr, mainWindow._handle, hInstance, 9, 0, 0, 0, 0, L"SplitClass", L"", 0, 
//};
	//ShowWindow(wd._handle, 1);
	//UpdateWindow(wd._handle);
	
	/*
	_splitWinDat = new WinDat();
	_splitWinDat->_handle = nullptr;
	_splitWinDat->_parent = _parentHandle;
	_splitWinDat->_hInstance = settings.hInstance;
	_splitWinDat->_var = 1;
	_splitWinDat->_className = L"SplitClass";
	_splitWinDat->_windowName = L"";
	_splitWinDat->_exStyle = 0;
	_splitWinDat->_style = WS_CHILD | WS_VISIBLE;



	if (_type == SplitType::HORIZONTAL) {
		_splitWinDat->_x = _x;
		_splitWinDat->_y = _y + _divLocY;
		_splitWinDat->_w = _w;
		_splitWinDat->_h = _divSize;

	}
	if (_type == SplitType::VERTICAL) {
		_splitWinDat->_x = _x + _divLocX;
		_splitWinDat->_y = _y;
		_splitWinDat->_w = _divSize;
		_splitWinDat->_h = _h;

	}
		
		*/
	//	_panelA->SetDimensions(_x, _y + _divLocY, _w, (_y + _divLocY + _divSize));
	//)_panelA->SetDimensions(_x + _divLocX, _y, (_x + _divLocX + _divSize), _h);


	//CreateSplitControl(*_splitWinDat);
}

SplitWindow* SplitWindow::GetA() {
	return _panelA;
}

SplitWindow* SplitWindow::GetB() {
	return _panelB;
}

SplitWindow* SplitWindow::SplitA(SplitType t, int loc) {
	_panelA = new SplitWindow(t, loc, _level, _parentHandle);
	if (_type == SplitType::HORIZONTAL)_panelA->SetDimensions(_x, _y, _w, _divLocY);
	else if (_type == SplitType::VERTICAL)_panelA->SetDimensions(_x, _y, _divLocX, _h);

	return _panelA;

}

SplitWindow* SplitWindow::SplitB(SplitType t, int loc) {
	_panelB = new SplitWindow(t, loc, _level, _parentHandle);
	if (_type == SplitType::HORIZONTAL)_panelB->SetDimensions(_x, _y +  _divLocY + _divSize, _w, _h - (_divLocY + _divSize));
	else if (_type == SplitType::VERTICAL)_panelB->SetDimensions(_divLocX + _divSize, _y, _w - (_divLocX + _divSize), _h);
	return _panelB;
}



void SplitWindow::SetDimensions(int x, int y, int w, int h) {
	_x = x;
	_y = y;
	_w = w;
	_h = h;
}

void SplitWindow::AttachA(WinDat* wd) {
	if (_panelA != nullptr) return;


	_winDatA = wd;
	if (_type == SplitType::HORIZONTAL) {
		_winDatA->_x = _x;
		_winDatA->_y = _y;
		_winDatA->_w = _w;
		_winDatA->_h = _divLocY;
	}
	else if (_type == SplitType::VERTICAL) {
		_winDatA->_x = _x;
		_winDatA->_y = _y;
		_winDatA->_w = _divLocX;
		_winDatA->_h = _h ;
	}


}
void SplitWindow::AttachB(WinDat* wd) {
	if (_panelB != nullptr) return;
	_winDatB = wd;

	if (_type == SplitType::HORIZONTAL) {
		_winDatB->_x = _x;
		_winDatB->_y = _y + _divLocY + _divSize;
		_winDatB->_w = _w;
		//_winDatB->_h = (_h - (_divLocY + _divSize)) - _y;
		_winDatB->_h = _h - (_divLocY + _divSize);
	}
	else if (_type == SplitType::VERTICAL) {
		_winDatB->_x = _x + _divLocX + _divSize;
		_winDatB->_y = _y + _divSize;
		_winDatB->_w = _w - (_divLocX + _divSize);
		_winDatB->_h = _h - _y;
	}
}

WinDat*  SplitWindow::GetWinDatA() {
	return _winDatA;
}
WinDat* SplitWindow::GetWinDatB() {
	return _winDatB;
}

