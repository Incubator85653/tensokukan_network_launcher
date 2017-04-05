#pragma once
// remember to link against shlwapi.lib
// in VC++ this can be done with
#pragma comment(lib, "Shlwapi.lib")

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <Shlwapi.h>

using namespace std;
#include <iostream>
#include <string>

namespace LibLauncher
{
	wstring iniFile_GetExeSelfFileName();
	wstring iniFile_GetCfgFilePath();
	wstring iniValue_GetValueByKey(wstring fileName, wstring appName, wstring key);
	void iniFile_WriteValueByKey(wstring fileName, wstring appName, wstring key);
};