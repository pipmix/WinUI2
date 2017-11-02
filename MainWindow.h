#pragma once
#include "SplitWindow.h"
#include "Menu.h"


void CreateMainWindow(WinDat& wd);


LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);