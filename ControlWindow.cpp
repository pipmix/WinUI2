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
}


