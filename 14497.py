import heapq

def func():
    n, m = map(int, input().split())
    v = [[0] * m for _ in range(n)]
    x1, y1, x2, y2 = map(int, input().split())
    x1 -= 1  # 0-indexed
    y1 -= 1  # 0-indexed
    x2 -= 1  # 0-indexed
    y2 -= 1  # 0-indexed
    que = []
    for i in range(n):
        line = input()
        for j in range(m):
            v[i][j] = 1 if not line[j].isdigit() else int(line[j])
    heapq.heappush(que, (1, x1, y1))  # Initial position with cost 1
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    while que:
        cnt, x, y = heapq.heappop(que)
        if x == x2 and y == y2:
            print(cnt - 1)
            return
        if v[x][y] == -1:
            continue
        v[x][y] = -1  # Mark as visited
        for delta_x, delta_y in directions:
            nx = x + delta_x
            ny = y + delta_y
            if 0 <= nx < n and 0 <= ny < m:
                if v[nx][ny] != -1:
                    new_cnt = cnt + (1 if v[nx][ny] == 1 else 0)
                    heapq.heappush(que, (new_cnt, nx, ny))
    print(-1)

if __name__ == "__main__":
    func()
