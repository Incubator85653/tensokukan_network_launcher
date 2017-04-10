#include "LibLicense.h"

bool LibLicense::GetActivationStatus() {
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
void LibLicense::UpdateTimesRun() {
	// Calculate new run times
	int newTimesRun = timesRun + 1;

	// Prepaid for WinAPI
	wstring appName = L"License";
	wstring keyName = L"TimesRun";
	wstring keyValue = LibUnit::Int2Wstring_Handwriting(newTimesRun);
	wstring fileName = Basic::IniFilePath();

	// Update License config file status
	// Remove free times to run
	// But ignore remove free times once app is activated.
	if (timesRun <= maxTimesRunFree && isActivated == 0) {
		LibIni::WriteKeyValue(appName,
			keyName,
			keyValue,
			fileName);
	}
}