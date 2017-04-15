#pragma once
// Windows API
// remember to link against shlwapi.lib
// in VC++ this can be done with
#pragma comment(lib, "Shlwapi.lib")
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Shlwapi.h>
// Std
#include <iostream>
#include <string>
using namespace std;

namespace LibUnit {
	extern string Wstring2String(wstring input);
	extern int String2Int(string input);
	extern int Wstring2Int(wstring input);
	// Simulate human writing
	// By default WinAPI will write the key value as bellow:
	//
	// [License]
	// TimesRun =1
	//
	// What we need:
	//
	// [License]
	// TimesRun = 1
	extern wstring Int2Wstring_Handwriting(int input);
	extern void WstringReplaceAll(std::wstring& str, const std::wstring& from, const std::wstring& to);
	extern wstring WstringSplitLines(wstring input);
}