#include <iostream>
#include <string>
#include "LibLicense.h"
#include "LibConfig.h"
#include "LibLauncher.h"

using namespace std;
int main() {
	LibLicense liblicense;

	wstring command = LibConfig::Autorun::Command();

	if (command == L"NothingFound") {
		wcout << L"Error: Can't find the key value or ini file." << endl
			<< L"	Error code: 1" << endl
			<< command << endl;
		cin.get();
	}
	else {
		if ( liblicense.GetActivationStatus() ) {
			using namespace LibLauncher::LibUnit;

			string prepaid_runCommand( Wstring2String(command) );
			int runCommand = system( prepaid_runCommand.c_str() );
		}
		else {
			wstring trialEnded = LibConfig::String::TrialEnded();

			wcout << trialEnded << endl;
			//wcout << L"The software free trial has ended." << endl
			//	<< L"Please buy the license to continue." << endl
			//	<< L"Press <Enter> to exit the program..." << endl;
			cin.get();
		}
	}
	liblicense.UpdateTimesRun();
	return 0;
}
