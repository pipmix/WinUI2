#pragma once
#include <windows.h>
#include "Settings.h"

extern Settings settings;

struct WindowProp {
	int x;
	int y;
	int w;
	int h;
	HWND handle;
	HWND parent;
	LPCWSTR windowName;
	LPCWSTR className;
	int styles;
	int exStyles;
};

struct Button_Prop {
	bool isPressed;
	bool heldDown;
};




class Button {
public:
	Button();
	void Register();
	void Create(HWND p, LPCWSTR str, int x, int y, int w, int h);

private:

	WindowProp winProp;
	Button_Prop butProp;



	static LRESULT CALLBACK ButtonWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

