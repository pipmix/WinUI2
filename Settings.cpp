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
}
