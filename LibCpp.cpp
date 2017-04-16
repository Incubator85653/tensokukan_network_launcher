#include "LibCpp.h"

wstring LibCpp::OsPathJoinSimulator(wstring pathA, wstring pathB) {
	wstring osPathSlash = L"\\";

	return pathA + osPathSlash + pathB;
}
wstring LibCpp::GetProgramSotragedPath() {
	// The code is come from
	// https://stackoverflow.com/questions/10814934/how-can-program-get-executable-name-of-itself

	TCHAR buffer[MAX_PATH] = { 0 };
	DWORD bufSize = sizeof(buffer) / sizeof(*buffer);
	// Get the fully-qualified path of the executable
	if (GetModuleFileNameW(NULL, buffer, bufSize) == bufSize)
	{
		// the buffer is too small, handle the error somehow
	}
	// now buffer = "c:\whatever\yourexecutable.exe"

	PathRemoveFileSpecW(buffer);
	// now out = "c:\whatever"

	// Convert to std::string
	wstring wsProgramSotragedPath(buffer);
	return wsProgramSotragedPath;
}
wstring LibCpp::GetProgramExeNameWithoutExt() {
	// The code is come from
	// https://stackoverflow.com/questions/10814934/how-can-program-get-executable-name-of-itself

	TCHAR buffer[MAX_PATH] = { 0 };
	TCHAR * out;
	DWORD bufSize = sizeof(buffer) / sizeof(*buffer);
	// Get the fully-qualified path of the executable
	if (GetModuleFileNameW(NULL, buffer, bufSize) == bufSize)
	{
		// the buffer is too small, handle the error somehow
	}
	// now buffer = "c:\whatever\yourexecutable.exe"

	// Go to the beginning of the file name
	out = PathFindFileNameW(buffer);
	// now out = "yourexecutable.exe"

	// Set the dot before the extension to 0 (terminate the string there)
	*(PathFindExtensionW(out)) = 0;
	// now out = "yourexecutable"

	// Convert to std::string
	wstring wsExeFileName(out);
	//wstring exeFileName(ws.begin(), ws.end());
	//cout << exeFileName << endl;
	return wsExeFileName;
}
void LibCpp::RunCommand(wstring command) {
	// Add abs path for command
	wstring commandAbsolutePath = LibCpp::OsPathJoinSimulator(LibCpp::GetProgramSotragedPath(), command);
	wstring doubleQuotes = L"\"";

	// Add double quotes to prevent space character caused execuate fail
	commandAbsolutePath = doubleQuotes + commandAbsolutePath + doubleQuotes;

	// Convert command to ANSI
	// Disable, use _wsystem instead
	//string prepaid_runCommand(LibUnit::Wstring2String(commandAbsolutePath));

	// Run the command use _wsystem for Unicode support
	int runCommand = _wsystem(commandAbsolutePath.c_str());
}