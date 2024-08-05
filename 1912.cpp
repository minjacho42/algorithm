#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n;
	int prev = 0;
	int ans;
	int num;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		prev = max(prev + num, num);
		// cout << ans << " " << prev << endl;
		if (i == 0)
			ans = prev;
		else
			ans = max(ans, prev);
	}
	cout << ans << endl;
}
