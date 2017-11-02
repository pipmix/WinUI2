#pragma once
#include <windows.h>
#include <tchar.h>
#include "WinDat.h"

extern Settings settings;

LRESULT CALLBACK SplitWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void CreateSplitControl(WinDat& wd);
void InitSplitControl();


class SplitControl;

struct SplitControlParam {
	friend class SplitControl;
	bool _isVertical = 0;
	int _divSize = 5;
	int _x = 0;
	int _y = 0;

	int _futureX = 0;
	int _futureY = 0;

	int _minX = 0;
	int _maxX = 0;
	int _minY = 0;
	int _maxY = 0;
	HCURSOR _cursor;
	COLORREF _backgroundColor;
	HBRUSH _backgroundBrush;
	HBRUSH _futureBrushl;
	HWND _hWnd;
};




class SplitControl{

	public:
		SplitControl(SplitControlParam* param);
		~SplitControl();

	private:

		SplitControlParam* _param;
		static LRESULT CALLBACK SplitControlProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		bool Init();
		void SetData(SplitControlParam* param);
		SplitControlParam* GetData();

		bool MouseMoveMessage();
		bool LeftButtonDownMessage();
		bool LeftButtonUpMessage();
		bool PaintMessage();
};


