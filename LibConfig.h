#pragma once
// Std
#include <string>
using namespace std;
// Etc
#include "LibIni.h"
#include "LibUnit.h"

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