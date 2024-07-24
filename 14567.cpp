#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	int arr[1001][1001] = {0, };
	map<int, int> result;
	deque<int> que;
	set<int> start_set;

	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		start_set.insert(i);
	}
	for (int i = 0; i < m; i++) {
		int pre, post;
		cin >> pre >> post;
		arr[pre][post] = 1;
		start_set.erase(post);
	}
	for (set<int>::iterator it = start_set.begin(); it != start_set.end(); it++) {
		que.push_back(*it);
		// cout << *it << endl;
	}
	// for (int i = 1; i < n+1; i++) {
	// 	for (int j = 1; j < n + 1; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int cnt = 0;
	while (que.size() > 0) {
		cnt++;
		int que_size = que.size();
		for (int i = 0; i < que_size; i++) {
			int num = que.front();
			que.pop_front();
			// cout << num << " " << cnt << endl;
			for (int j = 1; j < n + 1; j++) {
				if (arr[num][j] == 1) {
					arr[num][j] = 0;
					bool append = true;
					for (int k = 1; k < n + 1; k++) {
						if (arr[k][j] == 1) {
							append = false;
							break;
						}
					}
					if (append)
						que.push_back(j);
				}
			}
			// for (int i_ = 1; i_ < n+1; i_ ++) {
			// 	for (int j = 1; j < n + 1; j++) {
			// 		cout << arr[i_ ][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
			result[num] = cnt;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (i != 1)
			cout << " ";
		cout << result[i];
	}
	cout << endl;
}
