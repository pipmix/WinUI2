#pragma once
#include <windows.h>
#include <vector>

struct Tab {
	HWND _hWnd;
	LPCWSTR _text;
	bool _isActive;
	bool _isHighlighted;
	
};


class TabControl {
public:
	TabControl();
	~TabControl();
private:


	int _x;
	int _y;
	int _w;
	int _h;

	int _tabHeight;


	bool isTop;
	



	
};