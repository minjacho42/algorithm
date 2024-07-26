#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int n, r, c;
	int num = 0;
	cin >> n >> r >> c;

	for (int i = n; i >= 1; i--) {
		int quad;
		int width = pow(2, i);
		if (r < width / 2 && c < width / 2)
			quad = 0;
		else if (r < width / 2 && c >= width / 2)
			quad = 1;
		else if (r >= width / 2 && c < width / 2)
			quad = 2;
		else
			quad = 3;
		num += quad * pow(width / 2, 2);
		r %= width / 2;
		c %= width / 2;
	}
	cout << num << endl;
}
