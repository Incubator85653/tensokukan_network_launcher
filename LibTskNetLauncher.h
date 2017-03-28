#pragma once
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Shlwapi.h>

using namespace std;
#include <iostream>
#include <string>

class LibTskNetLauncher
{
public:
	wstring iniFile_GetExeSelfFileName();
	wstring iniFile_GetCfgFilePath();
	wstring iniValue_GetValueByKey(wstring fileName, wstring appName, wstring key);
};

// remember to link against shlwapi.lib
// in VC++ this can be done with
#pragma comment(lib, "Shlwapi.lib")