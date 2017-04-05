#pragma once
#include <string>
using namespace std;

class LibLicense
{
	static wstring cfgFilePath;

	static int isActivated;
	static int timesRun;
	static int maxTimesRunFree;
public:
	bool INI_GetActivationStatus();
	void INI_UpdateTimesRun();
};