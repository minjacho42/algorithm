#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string str1;
	string str2;
	int num = 0;
	char c;
	map<char, int> rom_digit = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	map<int, string> rom_digit_rev = 	{{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
										{10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
										{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
										{1000, "M"}};

	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++) {
		if (i != 0) {
			if (rom_digit[c] < rom_digit[str1[i]])
				num -= rom_digit[c];
			else
				num += rom_digit[c];
		}
		c = str1[i];
	}
	num += rom_digit[c];
	for (int i = 0; i < str2.length(); i++) {
		if (i != 0) {
			if (rom_digit[c] < rom_digit[str2[i]])
				num -= rom_digit[c];
			else
				num += rom_digit[c];
		}
		c = str2[i];
	}
	num += rom_digit[c];

	cout << num << endl;

	while (num > 0) {
		int digit = pow(10, static_cast<int>(log10(num)));
		// cout << digit << endl;
		// cout << static_cast<int>(num / digit) * digit << endl;
		if (rom_digit_rev.find(static_cast<int>(num / digit) * digit) != rom_digit_rev.end()) {
			cout << rom_digit_rev[static_cast<int>(num / digit) * digit];
			num -= static_cast<int>(num / digit) * digit;
		} else {
			if (static_cast<int>(num / digit) > 5) {
				cout << rom_digit_rev[digit * 5];
				num -= 5 * digit;
			} else {
				cout << rom_digit_rev[digit];
				num -= digit;
			}
		}
	}
	cout << endl;
}
