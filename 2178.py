from collections import deque

n, m = tuple(map(int, input().split()))
maze = []
for _ in range(n):
    maze.append(list(map(int,list(input()))))

visited = set()
que = deque()
que.append((0,0,1))
while que:
    x,y,cnt = que.popleft()
    if x == n-1 and y == m-1:
        print(cnt)
        break
    for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] == 1 and (nx,ny) not in visited:
            visited.add((nx,ny))
            que.append((nx,ny,cnt+1))