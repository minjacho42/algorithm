#include <iostream>
#include <vector>

using namespace std;

void check_possible(int *matchs, int *result, vector<bool>& v) {
	int match_idx = 0;
	int predict[6] = {0, };
	// for (int i = 0; i < 15; i++)
	// 	cout << matchs[i] << " ";
	// cout << "\n";
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (matchs[match_idx] == 2) {
				predict[i] += 100;
				predict[j] += 1;
			} else if (matchs[match_idx] == 1) {
				predict[i] += 10;
				predict[j] += 10;
			} else {
				predict[j] += 100;
				predict[i] += 1;
			}
			match_idx++;
		}
	}
	bool correct;
	for (int i = 0; i < 4; i++) {
		if (v[i])
			continue;
		correct = true;
		for (int j = 0; j < 6; j++) {
			if (predict[j] != result[6 * i + j])
				correct = false;
		}
		if (correct)
			v[i] = true;
	}
}

void recursive_check(int i, int *matchs, int *result, vector<bool>& v) {
	if (i == 15) {
		check_possible(matchs, result, v);
	} else {
		for (int match = 0; match < 3; match++) {
			matchs[i] = match;
			recursive_check(i + 1, matchs, result, v);
		}
	}
}

int main() {
	int result[24];
	int matchs[15];
	vector<bool> v;
	int w, d, l;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> w >> d >> l;
			result[6 * i + j] = w * 100 + d * 10 + l * 1;
			// cout << result[j] <<"\n";
		}
		v.push_back(false);
	}

	recursive_check(0, matchs, result, v);
	for (auto it = v.begin(); it != v.end(); it++) {
		if (it != v.begin())
			cout << " ";
		if (*it)
			cout << 1;
		else
			cout << 0;
	}
	cout << "\n";
}
