#include <iostream>
#include <cmath>

using namespace std;
int prime[10000001];

int main() {
	double prev_pow;
	unsigned long long a, b;
	int cnt;
	cnt = 0;
	cin >> a >> b;

	prime[0] = 0;
	prime[1] = 0;
	for (unsigned long long i = 2; i <= b / i; i++) {
		prime[i] = 1;
	}
	for (unsigned long long i = 2; i <= b / i; i++) {
		if (!prime[i])
			continue;
		for (unsigned long long j = i * 2; j <= b / j; j+=i) {
			prime[j] = 0;
		}
		for (prev_pow = i * i; prev_pow <= static_cast<double>(b); prev_pow *= i)
			if (prev_pow >= a)
				cnt++;
	}
	cout << cnt << endl;
}
