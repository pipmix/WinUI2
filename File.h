#pragma once
#include <windows.h>

#define BUFSIZE MAX_PATH

//wchar_t buf[BUFSIZE];

bool GetCurrentDir(wchar_t* buf) {

	DWORD dir = GetCurrentDirectoryW(BUFSIZE, buf);

	if (dir == 0) {
		buf = L"GetCurrentDirectoryW() failed";
		return 0;
	}
	if (dir > BUFSIZE) {
		buf = L"Buffer too small";
		return 0;
	}

	return 1;



}

bool SetCurrentDir(wchar_t* buf) {

	DWORD dir = SetCurrentDirectoryW(buf);

	if (dir == 0) return 0;

	return 1;
	
}

