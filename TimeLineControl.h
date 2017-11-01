#pragma once
#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK TimeLineWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND CreateTimeLineControl(HWND p);
void InitTimelineControl();