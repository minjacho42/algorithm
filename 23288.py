from collections import deque

n, m, k = map(int, input().split())
field = [[0 for j in range(m)] for i in range(n)]
dice = [6, 3, 5] # 아래, 오른쪽, 앞

def rotate(direction, dice, point):
    point_diff = {
        0 : (0, 1),
        1 : (1, 0),
        2 : (0, -1),
        3 : (-1, 0)
    }
    x, y = point
    dx, dy = point_diff[direction]
    nx, ny = x + dx, y + dy
    if nx < 0 or nx >= n or ny < 0 or ny >= m:
        direction = (direction + 2) % 4
    if direction == 0:
        new_dice = [dice[1], 7 - dice[0], dice[2]]
    elif direction == 1:
        new_dice = [dice[2], dice[1], 7 - dice[0]]
    elif direction == 2:
        new_dice = [7 - dice[1], dice[0], dice[2]]
    elif direction == 3:
        new_dice = [7 - dice[2], dice[1], dice[0]]
    else:
        new_dice = dice
    dx, dy = point_diff[direction]
    nx, ny = x + dx, y + dy
    return new_dice, (nx, ny), direction

def get_score(field, point):
    field_num = field[point[0]][point[1]]
    score = field_num
    visited = {point}
    que = deque()
    que.append(point)
    while len(que) > 0:
        x, y = que.popleft()
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in visited and field[nx][ny] == field_num:
                visited.add((nx, ny))
                score += field_num
                que.append((nx, ny))
    return score

for i in range(n):
    j = 0
    for num in map(int, input().split()):
        field[i][j] = num
        j += 1
total_score = 0
direction_idx = 0
point = [0, 0]
for cnt in range(k):
    dice, point, direction_idx = rotate(direction_idx, dice, point)
    total_score += get_score(field, point)
    cur_field = field[point[0]][point[1]]
    if dice[0] > cur_field:
        direction_idx = (direction_idx + 1) % 4
    elif dice[0] < cur_field:
        direction_idx = (direction_idx - 1) % 4
    # print(dice, point, direction_idx, total_score)
print(total_score)