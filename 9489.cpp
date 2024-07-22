#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

bool in_loop() {
	vector< set<int> > base_v;
	map<int, int> node_idx;
	vector<int> level_size;
	vector<int> nums;
	map<int, vector<int> > tree;
	int n, k;
	cin >> n >> k;
	if (n == 0 && k == 0)
		return true;
	int prev, curr;
	prev = 0;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> curr;
		nums.push_back(curr);
		cout << "curr : " << curr << endl;
		if (prev == 0) {
			node_idx[curr] = 0;
			cout << "node idx : " << node_idx[curr] << endl;
			s.insert(curr);
			base_v.push_back(s);
			s.clear();
		} else if (i != 1 && curr - prev > 1) {
			base_v.push_back(s);
			s.clear();
			s.insert(curr);
			node_idx[curr] = base_v.size();
			cout << "node idx : " << node_idx[curr] << endl;
		} else {
			s.insert(curr);
			node_idx[curr] = base_v.size();
			cout << "node idx : " << node_idx[curr] << endl;
		}
		prev = curr;
	}
	base_v.push_back(s);
	vector< set<int> >::iterator it = base_v.begin();
	int lv = 0;
	while (it != base_v.end()) {
		if (lv == 0) {
			level_size.push_back(1);
			lv++;
			if (it == base_v.end())
				break;
		} else {
			level_size.push_back(0);
			for (int i = 0; i < level_size[lv - 1]; i++) {
				level_size[lv] += (*it).size();
				it++;
				if (it == base_v.end())
					break;
			}
			lv++;
		}
	}
	for (int i = 0; i < level_size.size(); i++)
		cout << level_size[i] << endl;
	cout << "group idx : " << node_idx[k] << endl;
	return false;
}

int main() {
	while (true) {
		cout << "------" <<endl;
		if (in_loop())
			return (0);
	}
}
