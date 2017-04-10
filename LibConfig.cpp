#include "LibConfig.h"
using namespace LibConfig::Basic;

// [Basic]
wstring LibConfig::Basic::IniFilePath() {
	return LibIni::GetConfigFilePath();
}

// [Autorun]
wstring LibConfig::Autorun::Command() {
	return LibIni::GetKeyValue(L"Autorun",
		L"Command",
		IniFilePath());
}

// [License]
int LibConfig::License::IsActivated() {
	return LibUnit::Wstring2Int(
		LibIni::GetKeyValue(L"License",
			L"IsActivated",
			IniFilePath()));
}
int LibConfig::License::TimesRun() {
	return LibUnit::Wstring2Int(
		LibIni::GetKeyValue(L"License",
			L"TimesRun",
			IniFilePath()));
}
int LibConfig::License::MaxTimesRunFree() {
	return LibUnit::Wstring2Int(
		LibIni::GetKeyValue(L"License",
			L"MaxTimesRunFree",
			IniFilePath()));
}

// [String]
wstring LibConfig::String::TrialEnded() {
	return LibIni::GetKeyValue(L"String",
		L"TrialEnded",
		IniFilePath());
}