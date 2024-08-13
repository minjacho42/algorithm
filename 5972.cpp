#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	int node1, node2, price;

	unordered_map<int, vector<pair<int, int> > > graph;
	unordered_map<int, int> node_price;
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2 >> price;
		graph[node1].push_back(make_pair(node2, price));
		graph[node2].push_back(make_pair(node1, price));
	}
	deque<int> que;
	for (int i = 2; i < N + 1; i++)
		node_price[i] = -1;
	node_price[1] = 0;
	que.push_back(1);
	int cur_node;
	while (que.size() > 0) {
		cur_node = que.front();
		que.pop_front();
		for (auto it = graph[cur_node].begin(); it != graph[cur_node].end(); it++) {
			if (node_price[it->first] < 0 || node_price[it->first] > node_price[cur_node] + it->second) {
				node_price[it->first] = node_price[cur_node] + it->second;
				que.push_back(it->first);
			}
		}
	}
	cout << node_price[N] << "\n";
}
