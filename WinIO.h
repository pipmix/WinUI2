#pragma once
#include "CommonHeaders.h"


struct Directory {
	char name [64];
};

struct FileName {
	char name[64];
	char type[32];
};

bool CreateFile();

bool OpenFile(Directory d, FileName f) {
	HANDLE handle;

	handle = CreateFile(L"test", FILE_GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

}