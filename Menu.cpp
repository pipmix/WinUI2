#pragma once
#include "Menu.h"



HMENU AddMenuBar(HWND hWnd) {
	HMENU menuBar = CreateMenu();
	SetMenu(hWnd, menuBar);
	return menuBar;
}

HMENU AddMenuCategory(HMENU hMenu, LPCWSTR name) {

	HMENU category = CreateMenu();
	AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)category, name);



	return category;
}

HMENU AddMenuSubCategory(HMENU hMenu, LPCWSTR name) {

	HMENU subCategory = CreatePopupMenu();
	AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)subCategory, name);
	return subCategory;
}


bool AddMenuItem(HMENU hMenu, int id, LPCWSTR name) {

	return AppendMenuW(hMenu, MF_STRING, id, name);
}


bool AddMenuSeperator(HMENU hMenu) {
	return AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);

}