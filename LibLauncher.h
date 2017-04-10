#pragma once
// remember to link against shlwapi.lib
// in VC++ this can be done with
#pragma comment(lib, "Shlwapi.lib")

// Windows API
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Shlwapi.h>

#include <iostream>
#include <string>
using namespace std;

namespace LibLauncher {
	namespace LibIni {
		extern wstring GetKeyValue(wstring appName, wstring keyName, wstring fileName);
		extern wstring GetProgramSelfFileName();
		extern wstring GetConfigFilePath();
		extern void WriteKeyValue(wstring appName, wstring keyName, wstring keyValue, wstring fileName);
	}

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
	};
}