#include "LibIni.h"

wstring LibIni::GetKeyValue(wstring appName, wstring keyName, wstring fileName) {
	// Example:
	// [Connection]
	// Protocol = HTTP

	// Convert variable type for WinAPI
	LPCWSTR lpcWstrFileName = fileName.c_str();
	LPCWSTR lpcWstrAppName = appName.c_str();
	LPCWSTR lpcWstrKeyName = keyName.c_str();
	LPCWSTR lpcWstrKeyDefault = L"NothingFound";

	TCHAR inBuf[80];
	GetPrivateProfileStringW(lpcWstrAppName,
		lpcWstrKeyName,
		lpcWstrKeyDefault,
		inBuf,
		80,
		lpcWstrFileName);

	wstring result = &inBuf[0];
	return result;
}
wstring LibIni::GetConfigFilePath() {
	// Get exe file name but without file ext
	wstring exeSelfName = LibCpp::GetProgramExeNameWithoutExt();
	// Set config file ext
	wstring iniFileExt = L".ini";
	// Generate ini file name by using exe file name and ini file ext
	wstring iniFileName = exeSelfName + iniFileExt;

	// Generate absolute path to prevent working directory isn't same as program sotraged path
	wstring iniFilePath = LibCpp::OsPathJoinSimulator(LibCpp::GetProgramSotragedPath(), iniFileName);

	return iniFilePath;
}
void LibIni::WriteKeyValue(wstring appName, wstring keyName, wstring keyValue, wstring fileName) {
	// Convert variable type for WinAPI
	LPCWSTR lpcWstrAppName = appName.c_str();
	LPCWSTR lpcWstrKeyName = keyName.c_str();
	LPCWSTR lpcWstrKeyValue = keyValue.c_str();
	LPCWSTR lpcWstrFileName = fileName.c_str();

	WritePrivateProfileStringW(lpcWstrAppName,
		lpcWstrKeyName,
		lpcWstrKeyValue,
		lpcWstrFileName);
}