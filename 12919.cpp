#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool recur_check(const string& S, string& T) {
	if (S.length() == T.length()) {
		if (S == T)
			return true;
		else
			return false;
	} else {
		string backup_str = T;
		if (T.back() == 'A') {
			T = backup_str;
			T.pop_back();
			if (recur_check(S, T))
				return true;
		}
		if (T.front() == 'B') {
			T = backup_str;
			reverse(T.begin(), T.end());
			T.pop_back();
			if (recur_check(S, T))
				return true;
		}
		return false;
	}
}

int main() {
	string S;
	string revS;
	string T;

	cin >> S;
	cin >> T;
	revS = S;
	reverse(revS.begin(), revS.end());
	if (T.find(S) == string::npos && T.find(revS) == string::npos) {
		cout << 0;
		return 0;
	}
	if (recur_check(S, T))
		cout << 1;
	else
		cout << 0;
	cout << "\n";
}
