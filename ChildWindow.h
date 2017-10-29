#pragma once
#include "SplitWindow.h"



void CreateChildWindow(WinDat & wd);


LRESULT CALLBACK ChildWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
