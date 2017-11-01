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

	COLORREF backgroundColor;


};


static WindowSettings* settings;