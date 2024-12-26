from collections import deque

_ = input()
p_list = list(map(int, input().split()))
p_list = sorted(p_list)
que = deque(p_list)
prev_wait = 0
result = 0

while len(que) > 0:
	cur_wait = que.popleft()
	prev_wait += cur_wait
	result += prev_wait

print(result)
