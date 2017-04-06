#include "LibLicense.h"
#include "LibLauncher.h"
#include <iostream>
#include <string>
using namespace std;
using namespace LibLauncher;

wstring LibLicense::cfgFilePath = iniFile_GetCfgFilePath();

int LibLicense::isActivated = stoi(
	iniValue_GetValueByKey(L"License",
		L"IsActivated",
		cfgFilePath));
int LibLicense::timesRun = stoi(
	iniValue_GetValueByKey(L"License",
		L"TimesRun",
		cfgFilePath));
int LibLicense::maxTimesRunFree = stoi(
	iniValue_GetValueByKey(L"License",
		L"MaxTimesRunFree",
		cfgFilePath));

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
	// Calculate new run times
	int newTimesRun = timesRun + 1;
	
	// Prepaid for WinAPI
	wstring appName = L"License";
	wstring keyName = L"TimesRun";
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
	wstring keyValue = L" " + to_wstring(newTimesRun);
	wstring fileName = cfgFilePath;

	// Update License config file status
	// Remove free times to run
	// But ignore remove free times once app is activated.
	if (timesRun <= maxTimesRunFree && isActivated == 0) {
		iniFile_WriteValueByKey(appName,
			keyName,
			keyValue,
			fileName);
	};
}