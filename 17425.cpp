#include <iostream>

using namespace std;

int main() {
	unsigned long long g[1000001] = {0, };

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i < 1000001; i++) {
		for (int j = 1; i * j < 1000001; j++)
			g[j * i] += i;
		g[i] += g[i-1];
	}
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << g[n] << '\n';
	}
}
