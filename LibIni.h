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
// Etc
#include "LibCpp.h"

namespace LibIni {
	extern wstring GetKeyValue(wstring appName, wstring keyName, wstring fileName);
	extern wstring GetConfigFilePath();
	extern void WriteKeyValue(wstring appName, wstring keyName, wstring keyValue, wstring fileName);
}