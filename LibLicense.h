#pragma once
#include <string>
#include "LibConfig.h"
#include "LibLauncher.h"
using namespace std;
using namespace LibConfig;

class LibLicense {
private:
	int isActivated = License::IsActivated();
	int timesRun = License::TimesRun();
	int maxTimesRunFree = License::MaxTimesRunFree();
public:
	bool GetActivationStatus();
	void UpdateTimesRun();
};