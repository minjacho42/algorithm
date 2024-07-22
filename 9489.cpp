#include <string>
#include <map>
#include <iostream>

using namespace std;

struct node_s {
	int gp_idx;
	int p_idx;
	int num;
};

int main() {
	while (true) {
		int n, k;
		cin >> n >> k;
		if (n == 0 && k == 0)
			return 0;
		int num;
		struct node_s node_arr[1000];
		map<int, int> num_map;
		int p_idx = 0;
		int prev_num = 0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			num_map[num] = i;
			node_arr[i].num = num;
			// cout << "prev num : " << prev_num << " cur num : " << num << endl;
			if (prev_num != 0 && num - prev_num > 1) {
				if (i > 1) {
					// cout << "idx 증가" << endl;
					p_idx++;
				}
			}
			node_arr[i].p_idx = p_idx;
			node_arr[i].gp_idx = node_arr[p_idx].p_idx;
			prev_num = num;
			// cout << node_arr[i].num << " " << node_arr[i].p_idx << " " << node_arr[i].gp_idx << endl;
		}
		int idx = num_map[k];
		int result = 0;
		if (node_arr[idx].gp_idx == node_arr[idx].p_idx) {
			cout << result << endl;
		} else {
			for (int i = 0; i < n; i++) {
				if (node_arr[i].gp_idx == node_arr[idx].gp_idx && node_arr[i].p_idx != node_arr[idx].p_idx && node_arr[i].p_idx != node_arr[i].gp_idx)
					result += 1;
			}
			cout << result << endl;
		}
	}
}
