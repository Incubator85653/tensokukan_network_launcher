#include "LibLicense.h"
#include "LibLauncher.h"
#include <iostream>
#include <string>
using namespace std;
using namespace LibLauncher;

wstring LibLicense::cfgFilePath = iniFile_GetCfgFilePath();

int LibLicense::isActivated = stoi(
	iniValue_GetValueByKey(cfgFilePath,
		L"License",
		L"IsActivated"));
int LibLicense::timesRun = stoi(
	iniValue_GetValueByKey(cfgFilePath,
		L"License",
		L"TimesRun"));
int LibLicense::maxTimesRunFree = stoi(
	iniValue_GetValueByKey(cfgFilePath,
		L"License",
		L"MaxTimesRunFree"));

bool LibLicense::INI_GetActivationStatus()
{
	//wcout << isActivated << endl
	//	<< timesRun << endl
	//	<< maxTimesRunFree << endl;

	bool licenseStatus;
	if (isActivated > 0 || timesRun <= maxTimesRunFree) {
		licenseStatus = true;
	}
	else {
		licenseStatus = false;
	}

	return licenseStatus;
}
void LibLicense::INI_UpdateTimesRun() {
	wstring newTimesRun = to_wstring(timesRun + 1);
	wcout << newTimesRun << endl;
	cin.get();
	//TODO
	// The value is calculated, but not save after execute.

}