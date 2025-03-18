def count_building(diff_list):
    max_diff = 0
    cnt = 0
    if not diff_list:
        return 0
    for idx, diff in enumerate(diff_list):
        if idx == 0 or diff > max_diff:
            cnt += 1
            max_diff = diff
    return cnt

N = int(input())
heights = list(map(int, input().split()))
diffs = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(i + 1, N):
        diffs[i][j] = (heights[j] - heights[i]) / (j - i)
        diffs[j][i] = (heights[i] - heights[j]) / (j - i)
max_cnt = 0
for i in range(N):
    cnt = count_building(diffs[i][:i][::-1]) + count_building(diffs[i][i+1:])
    max_cnt = max(max_cnt, cnt)
print(max_cnt)
