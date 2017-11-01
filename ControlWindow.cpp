#include "ControlWindow.h"

void CreateControlWindow(WinDat& wd){

	wd._handle = CreateWindowEx(0, wd._className, NULL, wd._style, wd._x, wd._y, wd._w, wd._h, wd._parent, 0, NULL, NULL);


	HTREEITEM hRoot;


	TV_INSERTSTRUCT tvins;

	tvins = { 0 };

	tvins.hInsertAfter = TVI_ROOT;
	tvins.item.mask = TVIF_TEXT;
	tvins.item.pszText = L"Root";
	tvins.item.cchTextMax = 10;

	hRoot = TreeView_InsertItem(wd._handle, &tvins);

	//tvins.hInsertAfter = TVI_LAST;
	//tvins.item.pszText = "Child";
	//hChild = TreeView_InsertItem(hSidePanel, &tvins);


	ListViewAddItem(wd._handle, hRoot, L"test");
	ListViewAddItem(wd._handle, hRoot, L"cat");
	ListViewAddItem(wd._handle, ListViewAddItem(wd._handle, hRoot, L"murder"), L"more");

	tvins.hInsertAfter = TVI_ROOT;
	tvins.item.mask = TVIF_TEXT;
	tvins.item.pszText = L"Root2";
	tvins.item.cchTextMax = 10;

	hRoot = TreeView_InsertItem(wd._handle, &tvins);
}

HTREEITEM ListViewAddItem(HWND hWnd, HTREEITEM hItem, LPWSTR lpstr) {

	TVINSERTSTRUCT insert;
	insert = { 0 };

	insert.hParent = hItem;
	insert.hInsertAfter = TVI_LAST;
	insert.item.mask = TVIF_TEXT;
	insert.item.pszText = lpstr;
	insert.item.cchTextMax = 10;

	//HTREEITEM test = TVM_INSERTITEM(0, &insert);
	return TreeView_InsertItem(hWnd, &insert);

}