#include <iostream>
#include <string>
#include <wchar.h>
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
			// Get license wstring with "endl"
			wstring trialEnded = LibUnit::WstringSplitLines(LibConfig::String::TrialEnded());
			// Convert to local codepage string
			string trialEndedPrint = LibUnit::Wstring2String(trialEnded);
			
			// Display license information
			//TODO
			// The method can't display characters > 79 (Windows API return limit)
			// Need to find a way bypass it
			cout << trialEndedPrint << endl;
			cin.get();
		}
	}
	liblicense.UpdateTimesRun();
	return 0;
}
