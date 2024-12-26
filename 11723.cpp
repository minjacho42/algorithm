#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);
	int M;
	int s = 0;
	string op;
	int op_num;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> op;
		// cout << op_str << "\n";
		if (op == "all") {
			s = 0b11111111111111111111;
		}
		else if (op == "empty") {
			s = 0;
		}
		else {
			cin >> op_num;
			op_num--;
			if (op == "add")
				s |= 1 << op_num;
			else if (op == "remove") {
				s &= ~(1 << op_num);
			}
			else if (op == "check")
				cout << (s >> op_num & 1) << "\n";
			else if (op == "toggle")
				s ^= 1 << op_num;
		}
	}
}
