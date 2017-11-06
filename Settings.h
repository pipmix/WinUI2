#pragma once
#include <windows.h>

struct color {
	int r;
	int g;
	int b;
};

#define COLOR_DARK_RED color{156, 3,7 }

struct Colors {

	HBRUSH Button_Background;
	HBRUSH Button_Background_Selected;
	HBRUSH Button_Background_Hover;

	HBRUSH Button_Text;
	HBRUSH Button_Text_Selected;
	HBRUSH Button_Text_Hover;

	HBRUSH Button_Border;
	HBRUSH Button_Border_Selected;
	HBRUSH Button_Border_Hover;

};

class Settings {
	public:
		Settings();
		void Init(HWND h, HINSTANCE i);


		HWND hWnd;
		HINSTANCE hInstance;
		HCURSOR horzizontSplit;
		HCURSOR verticalSplit;
		HBRUSH splitBackgroundBrush;

		Colors colors;

};