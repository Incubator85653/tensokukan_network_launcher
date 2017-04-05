#include "LibLauncher.h"

wstring LibLauncher::iniValue_GetValueByKey(wstring appName, wstring keyName, wstring fileName) {
	// Example:
	// [Connection]
	// Protocol = HTTP

	LPCWSTR lpcWstrFileName = fileName.c_str();
	LPCWSTR lpcWstrAppName = appName.c_str();
	LPCWSTR lpcWstrKeyName = key.c_str();
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
wstring LibLauncher::iniFile_GetExeSelfFileName() {
	// The code is come from
	// https://stackoverflow.com/questions/10814934/how-can-program-get-executable-name-of-itself

	TCHAR buffer[MAX_PATH] = { 0 };
	TCHAR * out;
	DWORD bufSize = sizeof(buffer) / sizeof(*buffer);
	// Get the fully-qualified path of the executable
	if (GetModuleFileName(NULL, buffer, bufSize) == bufSize)
	{
		// the buffer is too small, handle the error somehow
	}
	// now buffer = "c:\whatever\yourexecutable.exe"

	// Go to the beginning of the file name
	out = PathFindFileName(buffer);
	// now out = "yourexecutable.exe"

	// Set the dot before the extension to 0 (terminate the string there)
	*(PathFindExtension(out)) = 0;
	// now out = "yourexecutable"

	// Convert to std::string
	wstring wsExeFileName(out);
	//wstring exeFileName(ws.begin(), ws.end());
	//cout << exeFileName << endl;
	return wsExeFileName;
}
wstring LibLauncher::iniFile_GetCfgFilePath() {
	wstring exeSelfName = LibLauncher::iniFile_GetExeSelfFileName();
	wstring iniFilePath = L".\\";
	wstring iniFileExt = L".ini";

	return iniFilePath + exeSelfName + iniFileExt;
}
void LibLauncher::iniFile_WriteValueByKey(wstring appName, wstring keyName, wstring keyValue, wstring fileName) {

}