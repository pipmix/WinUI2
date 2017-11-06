#include "Settings.h"

Settings::Settings()
{
}

void Settings::Init(HWND h, HINSTANCE i)
{
	hWnd = h;
	hInstance = i;

	horzizontSplit = LoadCursor(0, IDC_SIZEWE);
	verticalSplit = LoadCursor(0, IDC_SIZENS);

	splitBackgroundBrush = CreateSolidBrush(RGB(25, 25, 25));

	colors.Button_Background = CreateSolidBrush(RGB(156, 3, 7));
	colors.Button_Background_Selected = CreateSolidBrush(RGB(156, 100, 7));
	colors.Button_Background_Hover = CreateSolidBrush(RGB(156, 3, 100));

	colors.Button_Text = CreateSolidBrush(RGB(0, 0, 0));
	colors.Button_Text_Selected = CreateSolidBrush(RGB(255, 255, 255));
	colors.Button_Text_Hover = CreateSolidBrush(RGB(22, 255, 255));;

	colors.Button_Border = CreateSolidBrush(RGB(243, 124, 128));
	colors.Button_Border_Selected = CreateSolidBrush(RGB(106, 33, 173));
	colors.Button_Border_Hover = CreateSolidBrush(RGB(106, 108, 173));;
}


