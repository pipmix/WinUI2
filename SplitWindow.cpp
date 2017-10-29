#include "SplitWindow.h"

SplitWindow::SplitWindow(HWND h, SplitType t, int loc){

	_parentHandle = h;
	RECT clientRect;
	GetClientRect(_parentHandle, &clientRect);
	_x = clientRect.left;
	_y = clientRect.top;
	_w =  (clientRect.right - clientRect.left);
	_h = (clientRect.bottom - clientRect.top);

	_type = t;
	if (_type == SplitType::HORIZONTAL)_divLocY = loc;
	else if (_type == SplitType::VERTICAL)_divLocX = loc;

}

SplitWindow::SplitWindow(SplitType t, int loc){

	_type = t;
	if (_type == SplitType::HORIZONTAL)_divLocY = loc;
	else if (_type == SplitType::VERTICAL)_divLocX = loc;

}


SplitWindow* SplitWindow::GetA() {
	return _panelA;
}

SplitWindow* SplitWindow::GetB() {
	return _panelB;
}

SplitWindow* SplitWindow::SplitA(SplitType t, int loc) {
	_panelA = new SplitWindow(t, loc);
	if (_type == SplitType::HORIZONTAL)_panelA->SetDimensions(_x, _y, _w, _divLocY);
	else if (_type == SplitType::VERTICAL)_panelA->SetDimensions(_x, _y, _divLocX, _h);

	return _panelA;

}

SplitWindow* SplitWindow::SplitB(SplitType t, int loc) {
	_panelB = new SplitWindow(t, loc);
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

WinDat*  SplitWindow::GetWinDatA(WinDat* wd) {
	return _winDatA;
}
WinDat* SplitWindow::GetWinDatB(WinDat* wd) {
	return _winDatB;
}

