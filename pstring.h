#pragma once
#include "CommonHeaders.h"

#define PSTR_MAX 64

struct PString {
	char _data[PSTR_MAX];
	signed char _length;

	PString() {
		ClearString();
	}

	PString(char* text) {
		ClearString();
		SetString(text);
	}

	void ClearString() {
		_length = 0;
		memset(_data, 0, PSTR_MAX);
		_data[0] = '\0';
	}

	void SetString(char* text) {
		_length = strlen(text);
		memcpy(_data, text, _length);
		_data[_length] = '\0';
	}

	bool Append(PString s) {
		if ((_length + s._length) > PSTR_MAX) return 0;
		memcpy(_data + _length, s._data, s._length);
		_length += s._length;
		_data[_length] = '\0';
		return 1;
	}

	bool Prepend(PString s) {
		if ((_length + s._length) > PSTR_MAX) return 0;
		memmove(_data + s._length, _data, _length);
		memcpy(_data, s._data, s._length);
		_length += s._length;
		return 1;

	}

	char* GetDataAsChar() {
		if (_length == 0) return "";
		char* tData = new char[_length];
		memcpy(tData, _data, _length);
		tData[_length] = '\0';
		return tData;
	}

	wchar_t* GetDataAsWChar() {
		if (_length == 0) return L"";
		wchar_t* tData = new wchar_t[_length];

		tData[0] = 'a';
		tData[1] = 'b';
		tData[2] = '\0';
		return tData;
	}

};
