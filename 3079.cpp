#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	unsigned long long n, m;
	unsigned long long res = 0;
	vector<unsigned long long> gate_vec;

	cin >> n >> m;
	for (unsigned long long i = 0; i < n; i++) {
		unsigned long long num;
		cin >> num;
		gate_vec.push_back(num);
	}
	sort(gate_vec.begin(), gate_vec.end());
	unsigned long long low = 1;
	unsigned long long high = *(gate_vec.begin()) * m;
	unsigned long long mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		unsigned long long max_people = 0;
		for (vector<unsigned long long>::iterator it = gate_vec.begin(); it != gate_vec.end(); it++) {
			max_people += mid / *it;
		}
		if (max_people >= m) {
			if (res > mid || res == 0)
				res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << res << endl;
}
