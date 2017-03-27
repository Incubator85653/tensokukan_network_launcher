#include "LibTskNetLauncher.h"

using namespace std;
#include <iostream>
#include <string>

int main(){
	LibTskNetLauncher LibLauncher;
	string selfName = LibLauncher.ExeSelfFileName();
	cout << selfName << endl;
	cin.get();
	return 0;
}

