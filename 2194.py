from collections import deque

n, m, a, b, k = tuple(map(int, input().split()))
maze = [[0 for i in range(m)] for j in range(n)]
for _ in range(k):
    wall_row, wall_col = map(int, input().split())
    wall_row -= 1
    wall_col -= 1
    for i in range(a):
        for j in range(b):
            if 0 <= wall_row - i < n and 0 <= wall_col - j < m:
                maze[wall_row - i][wall_col - j] = -1
start_x, start_y = tuple(map(int, input().split()))
start_x -= 1
start_y -= 1
end_x, end_y = tuple(map(int, input().split()))
end_x -= 1
end_y -= 1

que = deque()
maze[start_x][start_y] = 1
que.appendleft((start_x, start_y))
have_path = False
while len(que) > 0:
    x, y = que.pop()
    if x == end_x and y == end_y:
        print(maze[x][y] - 1)
        have_path = True
        break
    cnt = maze[x][y]
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx <= n - a and 0 <= ny <= m - b:
            if maze[nx][ny] == 0 or maze[nx][ny] > cnt + 1:
                maze[nx][ny] = cnt + 1
                que.appendleft((nx, ny))
if not have_path:
    print(-1)