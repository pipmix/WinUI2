#pragma once
#include "CommonHeaders.h"


enum PANEL_ORIENTATION{
	VERTICAL, HORIZONTAL, QUAD
};

enum PANEL_TYPE {
	TREEVIEW, LISTVIEW
};


class  Panel{
	public:
		 Panel(HWND parentHandle, PANEL_TYPE pt, PANEL_ORIENTATION po, std::string name);
		~ Panel();
		void Init();

		LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);


	private:

		HWND _parentHwnd;
		HWND _hwnd;
		LPCWSTR _className;
		LPCWSTR _windowName;
		PANEL_TYPE _panelType
};


static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);