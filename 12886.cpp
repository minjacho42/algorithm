#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int visited[1001][1001];

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	if ((a + b + c) % 3 != 0) {
		cout << 0 << "\n";
		return 0;
	}
	if (a == b && b== c) {
		cout << 1 << "\n";
		return 0;
	}
	else {
		deque<pair<int, int> > que;
		visited[a][b] = 1;
		que.push_back(make_pair(a, b));
		while (que.size() > 0) {
			int x = que.front().first;
			int y = que.front().second;
			int z = (a + b + c) - (x + y);
			// cout << x << " " << y << " " << z<< "\n";
			que.pop_front();
			vector<pair<int, int> > vec;
			vec.push_back(make_pair(x, y));
			vec.push_back(make_pair(y, z));
			vec.push_back(make_pair(x, z));
			for (auto it = vec.begin(); it != vec.end(); it++) {
				int new_x = it->first;
				int new_y = it->second;
				int new_z = (a + b + c) - (new_x + new_y);
				// cout << new_x << " " << new_y << " " << new_z << "\n";
				if (new_x > new_y) {
					new_x -= new_y;
					new_y += new_y;
				} else if (new_x < new_y) {
					new_y -= new_x;
					new_x += new_x;
				} else
					continue;
				if (new_x == new_y && new_y == new_z) {
					cout << 1 << "\n";
					return 0;
				}
				// cout << new_x << " " << new_y << " " << new_z << "\n";
				int que_first = min(min(new_x, new_y), new_z);
				int que_second = max(max(new_x, new_y), new_z);
				// cout << que_first << " " << que_second << "\n";
				if (!visited[que_first][que_second]) {
					visited[que_first][que_second] = 1;
					que.push_back(make_pair(que_first, que_second));
				}
			}
		}
		cout << 0 << "\n";
	}
}
