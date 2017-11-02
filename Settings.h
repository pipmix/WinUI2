#pragma once
#include <windows.h>

class Settings {
	public:
		Settings();
		void Init(HWND h, HINSTANCE i);


		HWND hWnd;
		HINSTANCE hInstance;
		HCURSOR horzizontSplit;
		HCURSOR verticalSplit;
		HBRUSH splitBackgroundBrush;



};