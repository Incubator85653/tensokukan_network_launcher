#include <iostream>
#include <string>
#include "LibLicense.h"
#include "LibLauncher.h"

using namespace std;
using namespace LibLauncher;

int main() {
	LibLicense liblicense;

	wstring iniFilePath = iniFile_GetCfgFilePath();
	wstring appName = L"Autorun";
	wstring appKey = L"Command";
	wstring command = iniValue_GetValueByKey(appName, appKey, iniFilePath);

	if (command == L"NothingFound") {
		wcout << L"Error: Can't find the key value or ini file." << endl
			<< command << endl;
		cin.get();
	}
	else {
		if (liblicense.INI_GetActivationStatus()) {
			string command_std_string(command.begin(), command.end());
			int runCommand = system(command_std_string.c_str());
		}
		else {
			wcout << L"The software free trial has ended." << endl
				<< L"Please buy the license to continue." << endl
				<< L"Press <Enter> to exit the program..." << endl;
			cin.get();
		}
	}
	liblicense.INI_UpdateTimesRun();
	return 0;
}
