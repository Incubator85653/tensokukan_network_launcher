#pragma once
#include <string>
#include "LibLauncher.h"
using namespace std;
using namespace LibLauncher;
// Use UCS-2 LE with BOM as the file format

namespace LibConfig {
	namespace Basic {
		extern wstring IniFilePath();
	}
	namespace Autorun {
		extern wstring Command();
	}
	namespace License {
		extern int IsActivated();
		extern int TimesRun();
		extern int MaxTimesRunFree();
	}
	namespace String {
		extern wstring TrialEnded();
	}
}