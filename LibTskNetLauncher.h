#pragma once
#include <windows.h>
#include <Shlwapi.h>

using namespace std;
#include <iostream>
#include <string>

class LibTskNetLauncher
{
public:
	string ExeSelfFileName();
};

// remember to link against shlwapi.lib
// in VC++ this can be done with
#pragma comment(lib, "Shlwapi.lib")