#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> v;
		int cnt = 0;
		int n,m,k,price;
		cin >> n >> m >> k;
		for (int j = 0; j < n; j++) {
			cin >> price;
			v.push_back(price);
		}
		int j = 0;
		if (n == m) {
			if (accumulate(v.begin(), v.end(), 0) < k)
				cout << 1 << endl;
			else {
				cout << 0 << endl;
			}
			continue;
		}
		while (j < v.size()) {
			if (j == 0) {
				price = accumulate(v.begin(), v.begin() + m, 0);
			} else {
				price -= v[j - 1];
				price += v[(j + m - 1) % v.size()];
			}
			if (price < k)
				cnt++;
			j++;
		}
		cout << cnt << endl;
	}
}
