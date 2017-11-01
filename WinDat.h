#pragma once
#include <windows.h>
#include <commctrl.h>
#include <tchar.h>
#include <Strsafe.h>


#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Comctl32.lib")


struct WinDat {
	HWND _handle = nullptr;
	HWND _parent = nullptr;
	HINSTANCE _hInstance = nullptr;
	int _var = 0;
	int _x = 0;
	int _y = 0;
	int _w = 0;
	int _h = 0;
	LPCTSTR _className = L"";
	LPCTSTR _windowName = L"";
	DWORD _exStyle = 0;
	DWORD _style = 0;
};



struct WindowSettings{

	COLORREF darkBackground = RGB(55,55,55);
	COLORREF lightBackground = RGB(100, 100, 100);
	COLORREF backgroundColor = RGB(51, 153, 255);

};


static WindowSettings settings;