#pragma once
#include "RightClick.h"


HMENU AddMenuBar(HWND hWnd);

HMENU AddMenuCategory(HMENU hMenu, LPCWSTR name);

HMENU AddMenuSubCategory(HMENU hMenu, LPCWSTR name);

bool AddMenuItem(HMENU hMenu, int id, LPCWSTR name);

bool AddMenuSeperator(HMENU hMenu);