#include <algorithm>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

int main() {
	int plate_cnt, sushi_kind, window_size, coupon, plate;
	int del_plate, max_cnt, cur_cnt;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> plate_cnt >> sushi_kind >> window_size >> coupon;

	int eaten_sushi_map[3001] = {0, };
	deque<int> eaten_sushi_que;
	deque<int> tmp_sushi_que;
	eaten_sushi_map[coupon] = 1;
	max_cnt = 1;
	cur_cnt = 1;
	for (int i = 0; i < plate_cnt; i++) {
		cin >> plate;
		eaten_sushi_que.push_back(plate);
		if (eaten_sushi_map[plate] == 0)
			cur_cnt += 1;
		eaten_sushi_map[plate] += 1;
		if (i >= window_size) {
			del_plate = eaten_sushi_que.front();
			eaten_sushi_que.pop_front();
			eaten_sushi_map[del_plate] -= 1;
			if (eaten_sushi_map[del_plate] == 0)
				cur_cnt -= 1;
		} else if (i != window_size - 1){
			tmp_sushi_que.push_back(plate);
		}
		max_cnt = max(max_cnt, cur_cnt);
	}
	if (plate_cnt != window_size) {
		for (auto it = tmp_sushi_que.begin(); it != tmp_sushi_que.end(); it++) {
			plate = *it;
			eaten_sushi_que.push_back(plate);
			if (eaten_sushi_map[plate] == 0)
				cur_cnt += 1;
			eaten_sushi_map[plate] += 1;
			del_plate = eaten_sushi_que.front();
			eaten_sushi_que.pop_front();
			eaten_sushi_map[del_plate] -= 1;
			if (eaten_sushi_map[del_plate] == 0)
				cur_cnt -= 1;
			max_cnt = max(max_cnt, cur_cnt);
		}
	}
	cout << max_cnt << endl;
}
