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
#include "LibIni.h"
#include "LibUnit.h"

namespace LibCpp {
	extern void RunCommand(wstring command);
	extern wstring GetProgramSotragedPath();
	extern wstring GetProgramExeNameWithoutExt();
	extern wstring OsPathJoinSimulator(wstring pathA, wstring pathB);
}
