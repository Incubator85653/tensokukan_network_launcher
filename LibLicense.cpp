#include "LibLicense.h"
#include "LibTskNetLauncher.h"

bool LibLicense::INI_GetActivationStatus()
{
	LibTskNetLauncher LibLauncher;
	wstring cfgFilePath = LibLauncher.iniFile_GetCfgFilePath();

	int isActivated = stoi(
		LibLauncher.iniValue_GetValueByKey(cfgFilePath,
			L"License",
			L"IsActivated") );
	int timesRun = stoi(
		LibLauncher.iniValue_GetValueByKey(cfgFilePath,
			L"License",
			L"TimesRun") );
	int maxTimesRunFree = stoi(
		LibLauncher.iniValue_GetValueByKey(cfgFilePath,
			L"License",
			L"MaxTimesRunFree") );

	wcout << isActivated << endl
		<< timesRun << endl
		<< maxTimesRunFree << endl;

	bool licenseStatus;
	if (isActivated > 0 || timesRun <= maxTimesRunFree) {
		licenseStatus = true;
	}
	else {
		licenseStatus = false;
	}

	return licenseStatus;
}