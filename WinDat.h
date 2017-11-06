#pragma once
#include <windows.h>
#include <commctrl.h>
#include <tchar.h>
#include <Strsafe.h>
#include "Settings.h"
#include "RightClick.h"


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



struct FuncDefine {
	int id;
	void* func;
};

struct WindowData {
	HWND handle;
	HWND parent;
	HINSTANCE instance;
	int var;
	int x;
	int y;
	int w;
	int h;
	LPCWSTR className;
	LPCWSTR windowName;
	DWORD exStyles;
	DWORD styles;
	
};