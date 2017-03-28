#include "LibTskNetLauncher.h"
#include "LibLicense.h"

using namespace std;
#include <iostream>
#include <string>

int main() {
	LibTskNetLauncher libLauncher;
	LibLicense libLicense;

	wstring iniFilePath = libLauncher.iniFile_GetCfgFilePath();
	wstring appName = L"Autorun";
	wstring appKey = L"Command";
	wstring command = libLauncher.iniValue_GetValueByKey(iniFilePath, appName, appKey);

	if (command == L"NothingFound") {
		wcout << L"Error: Can't find the key value or ini file." << endl
			<< command << endl;
		cin.get();
	}
	else {
		if (libLicense.INI_GetActivationStatus()) {
			string command_std_string(command.begin(), command.end());
			int runCommand = system(command_std_string.c_str());
		}
		else {
			wcout << L"The software free trial has ended." << endl
				<< L"Please buy the license to continue." << endl
				<< L"Press <Enter> to exit the program..." << endl;
			cin.get();
		}
		return 0;
	}
}
