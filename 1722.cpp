#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long facto(int n) {
	unsigned long long num = 1;
	for (int i = n; i >= 1; i--) {
		num *= i;
	}
	return num;
}

size_t get_idx(vector<int>& v, int num) {
	vector<int>::iterator it = find(v.begin(), v.end(), num);
	size_t index = distance(v.begin(), it);
	v.erase(it);
	return index;
}

int main() {
	int N;
	cin >> N;
	int p_num;
	vector<int> v;
	cin >> p_num;
	for (int i = 0; i < N; i++)
		v.push_back(i + 1);
	if (p_num == 1) {
		unsigned long long nth;
		cin >> nth;
		nth--;
		for (int i = N - 1; i >= 1; i--) {
			int kth = nth / facto(i);
			nth = nth % facto(i);
			cout << v[kth] << " ";
			v.erase(v.begin() + kth);
		}
		cout << v[0] << "\n";
	} else {
		int v_num;
		unsigned long long res = 1;
		for (int i = N - 1; i >= 1; i--) {
			cin >> v_num;
			unsigned long long res_i = facto(i) * get_idx(v, v_num);
			// cout << res_i;
			res += res_i;
		}
		cout << res << "\n";
	}
}
