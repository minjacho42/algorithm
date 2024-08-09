#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int map[501][501];
int dp[501][501];
int M;
int N;
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(int i, int j) {
	int result = 0;
	if (i == M && j == N)
		return 1;
	if (dp[i][j] >= 0)
		return dp[i][j];
	for (int it = 0; it < 4; it++) {
		if (i + directions[it][0] < 1 || i + directions[it][0] > M || j + directions[it][1] < 1 || j + directions[it][1] > N)
			continue;
		if (map[i + directions[it][0]][j + directions[it][1]] >= map[i][j])
			continue;
		result += dfs(i + directions[it][0], j + directions[it][1]);
	}
	dp[i][j] = result;
	return (result);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i+1][j+1];
			dp[i+1][j+1] = -1;
		}
	}
	cout << dfs(1,1) << "\n";

}
