#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1;
	int num1 = 0;
	string str2;
	int num2 = 0;
	char c;
	map<char, int> rom_digit = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++) {
		if (i != 0) {
			if (rom_digit[c] < rom_digit[str1[i]])
				num1 -= rom_digit[c];
			else
				num1 += rom_digit[c];
		}
		c = str1[i];
	}
	num1 += rom_digit[c];

	for (int i = 0; i < str2.length(); i++) {
		if (i != 0) {
			if (rom_digit[c] < rom_digit[str2[i]])
				num2 -= rom_digit[c];
			else
				num2 += rom_digit[c];
		}
		c = str2[i];
	}
	num2 += rom_digit[c];

	cout << num1 + num2 << endl;
}
