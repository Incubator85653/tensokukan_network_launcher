#include "LibTskNetLauncher.h"

using namespace std;
#include <iostream>
#include <string>

int main(){
	LibTskNetLauncher LibLauncher;

	wstring selfName = LibLauncher.ExeSelfFileName();
	wstring appName = L"Autorun";
	wstring appKey = L"Command";

	wstring command = LibLauncher.INI_GetValueByKey(selfName, appName, appKey);
	if (command == L"NothingFound") {
		wcout << L"Can't find the key value or ini file." << endl
			  << command << endl;
		cin.get();
	}
	else {
		string command_std_string(command.begin(), command.end());
		int runCommand = system(command_std_string.c_str());
	}
	return 0;
}

