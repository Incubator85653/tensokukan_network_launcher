#include "LibTskNetLauncher.h"

string LibTskNetLauncher::ExeSelfFileName() {
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
	wstring ws(out);
	string exeFileName(ws.begin(), ws.end());
	//cout << exeFileName << endl;
	return exeFileName;
}