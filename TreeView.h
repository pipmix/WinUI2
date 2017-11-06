#pragma once
#include <windows.h>
#include <commctrl.h>

HWND CreateTreView(HWND hWnd) {

	HWND h;
	return h;
}

HTREEITEM AddItem(HWND hWnd, LPCWSTR name, int lvl) {
	TVITEM item;
	TVINSERTSTRUCT insert;


}


HTREEITEM InsertItem(HWND hWnd, HTREEITEM parentItem, HTREEITEM insertAfter, LPCWSTR text, int image, LPARAM param) {

	TVITEM item = { 0 };
	item.mask = TVIF_TEXT | TVIF_PARAM;
	item.pszText = const_cast<LPWSTR>(text);
	item.lParam = param;

	if (image > -1) {
		item.mask |= TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		item.iImage = image;
		item.iSelectedImage = image;
	}

	TVINSERTSTRUCT insertStruct = { 0 };
	insertStruct.item = item;
	insertStruct.hInsertAfter = insertAfter;
	insertStruct.hParent = parentItem;

	return TreeView_InsertItem(hWnd, &insertStruct);

}

HTREEITEM insertItem(const wchar_t* str, HWND hwnd, HTREEITEM parentItem, HTREEITEM insertAfter, int imageIndex, int selectedImageIndex){

	TVINSERTSTRUCT insertStruct;
	insertStruct.hParent = parentItem;
	insertStruct.hInsertAfter = insertAfter;
	insertStruct.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	insertStruct.item.pszText = (LPWSTR)str;
	insertStruct.item.cchTextMax = sizeof(str) / sizeof(str[0]);
	insertStruct.item.iImage = imageIndex;
	insertStruct.item.iSelectedImage = selectedImageIndex;

	// insert the item
	return (HTREEITEM)::SendMessage(hwnd, TVM_INSERTITEM,
		0, (LPARAM)&insertStruct);
}

HIMAGELIST CreateImageList() {
	/*
	HIMAGELIST imageList = ImageList_Create(32, 32, ILC_COLORDDB | ILC_MASK, 2, 1);

	HICON icon = (HICON)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDI_FOLDERCLOSED), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);

	ImageList_AddIcon(imageList, icon);

	icon = (HICON)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDI_FOLDEROPEN), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);

	ImageList_AddIcon(imageList, icon);

	SendMessage(tvHandle, TVM_SETIMAGELIST,
		(WPARAM)TVSIL_NORMAL, (LPARAM)imageList);

	return imageList;
	*/
	return 0;
}
	
