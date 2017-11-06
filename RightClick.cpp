#include "RightClick.h"


void RightClick(HWND hWnd, LPARAM lParam) {
	HMENU hMenu;
	POINT point;
	point.x = LOWORD(lParam);
	point.y = HIWORD(lParam);

	hMenu = CreatePopupMenu();
	ClientToScreen(hWnd, &point);
	AppendMenuW(hMenu, MF_STRING, 555, L"&New");
	AppendMenuW(hMenu, MF_STRING, 564, L"&Open");
	AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
	AppendMenuW(hMenu, MF_STRING, 476, L"&Quit");

	TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, point.x, point.y, 0, hWnd, NULL);
	DestroyMenu(hMenu);

}