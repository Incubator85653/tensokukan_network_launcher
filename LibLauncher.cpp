#include "LibLauncher.h"

wstring LibLauncher::LibIni::GetKeyValue(wstring appName, wstring keyName, wstring fileName) {
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
wstring LibLauncher::LibIni::GetProgramSelfFileName() {
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
wstring LibLauncher::LibIni::GetConfigFilePath() {
	wstring exeSelfName = LibLauncher::LibIni::GetProgramSelfFileName();
	wstring iniFilePath = L".\\";
	wstring iniFileExt = L".ini";

	return iniFilePath + exeSelfName + iniFileExt;
}
void LibLauncher::LibIni::WriteKeyValue(wstring appName, wstring keyName, wstring keyValue, wstring fileName) {
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

string LibLauncher::LibUnit::Wstring2String(wstring input) {
	// Learn how does he did it
	auto cp = GetConsoleOutputCP();
	auto len = WideCharToMultiByte(cp, 0, input.c_str(), input.length(), nullptr, 0, nullptr, nullptr);
	char *buf = new char[len];
	WideCharToMultiByte(cp, 0, input.c_str(), input.length(), buf, len, nullptr, nullptr);

	string result(buf, len);
	delete[] buf;

	return result;
}
int LibLauncher::LibUnit::String2Int(string input) {
	int result = stoi(input);

	return result;
}
int LibLauncher::LibUnit::Wstring2Int(wstring input) {
	string prepaid_stoi = Wstring2String(input);
	int result = stoi(prepaid_stoi);

	return result;
}
wstring LibLauncher::LibUnit::Int2Wstring_Handwriting(int input) {
	string prepaid_wstring = " " + to_string(input);

	wstring result(prepaid_wstring.begin(), prepaid_wstring.end());

	return result;
}