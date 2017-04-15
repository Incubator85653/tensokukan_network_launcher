#include "LibUnit.h"

string LibUnit::Wstring2String(wstring input) {
	// Learn how does he did it
	auto cp = GetConsoleOutputCP();
	auto len = WideCharToMultiByte(cp, 0, input.c_str(), input.length(), nullptr, 0, nullptr, nullptr);
	char *buf = new char[len];
	WideCharToMultiByte(cp, 0, input.c_str(), input.length(), buf, len, nullptr, nullptr);

	string result(buf, len);
	delete[] buf;

	return result;
}
int LibUnit::String2Int(string input) {
	int result = stoi(input);

	return result;
}
int LibUnit::Wstring2Int(wstring input) {
	string prepaid_stoi = Wstring2String(input);
	int result = stoi(prepaid_stoi);

	return result;
}
wstring LibUnit::Int2Wstring_Handwriting(int input) {
	string prepaid_wstring = " " + to_string(input);

	wstring result(prepaid_wstring.begin(), prepaid_wstring.end());

	return result;
}
void LibUnit::WstringReplaceAll(std::wstring& str, const std::wstring& from, const std::wstring& to) {
	// https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string

	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::wstring::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}
wstring LibUnit::WstringSplitLines(wstring input) {
	// Create a copy
	wstring wstr_copy = input;

	// Place some conditions
	wstring textToReplace = L"\\n";
	wstring newWstring = L"\n";

	LibUnit::WstringReplaceAll(wstr_copy, textToReplace, newWstring);
	return wstr_copy;
}