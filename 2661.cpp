#include <iostream>

using namespace std;

bool check_good_arr(int *arr, const int n) {
	bool result = true;
	bool iter_result;
	for (int i = 2; i <= n/2; i++) {
		iter_result = false;
		for (int j = 0; j < i; j++) {
			if (arr[n - 1 - j] != arr[n - 1 - j - i]) {
				iter_result = true;
				break;
			}
		}
		if (!iter_result)
		{
			// cout << "false : ";
			// for (int x = 0; x < n; x++) {
			// 	cout << arr[x];
			// }
			// cout << endl;
			return false;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i];
	// }
	// cout << endl;
	return true;
}

bool backtrack(int *arr, int i, const int n) {
	if (i == n) {
		return (check_good_arr(arr, n));
	} else {
		for (int num = 1; num < 4; num++) {
			if (i != 0 && arr[i - 1] == num)
				continue;
			arr[i] = num;
			if (check_good_arr(arr, i)) {
				if (backtrack(arr, i + 1, n))
					return true;
			}
		}
		return false;
	}
}

int main() {
	int arr[80] = {0, };
	int n;

	cin >> n;
	backtrack(arr, 0, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << "\n";
}
