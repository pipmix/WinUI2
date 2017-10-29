#pragma once
#include "WinDat.h"

struct WinProp {
	HWND _handle;
	int _x;
	int _y;
	int _w;
	int _h;

};


enum class SplitType {
	HORIZONTAL, VERTICAL, QUAD
};

class SplitWindow {

public:

	SplitWindow(HWND h, SplitType t, int loc);
	SplitWindow(SplitType t, int loc);



	SplitWindow* GetA();
	SplitWindow* GetB();


	SplitWindow* SplitA(SplitType st, int l);
	SplitWindow* SplitB(SplitType st, int l);

	void AttachA(WinDat* wd);
	void AttachB(WinDat* wd);

	WinDat*  GetWinDatA(WinDat* wd);
	WinDat*  GetWinDatB(WinDat* wd);

	int _x = 0;
	int _y = 0;
	int _w = 0;
	int _h = 0;


private:

	void SetDimensions(int x, int y, int w, int h);
	SplitType _type = SplitType::HORIZONTAL;
	int _divLocX = 0;
	int _divLocY = 0;
	SplitWindow* _panelA = nullptr;
	SplitWindow* _panelB = nullptr;
	HWND _parentHandle = nullptr;
	HWND _handle1 = nullptr;
	HWND _handle2 = nullptr;

	int _divSize = 5;

	WinDat* _winDatA;
	WinDat* _winDatB;

};