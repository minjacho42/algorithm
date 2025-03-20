from collections import deque

def set_generator(left_bottom, right_top):
    x1, y1 = left_bottom
    x2, y2 = right_top
    point_set = set()
    for i in range(x1, x2):
        for j in range(y1, y2):
            point_set.add((i, j))
    print(point_set)
    return point_set

m,n,k = tuple(map(int, input().split()))
areas = []
for _ in range(k):
    areas.append(tuple(map(int, input().split())))
total_points = set_generator((0, 0), (m, n))
for area in areas:
    x1, y1, x2, y2 = area
    total_points -= set_generator((x1, y1), (x2, y2))

bfs_queue = deque()
area_sizes = []
while len(total_points) > 0:
    start_point = total_points.pop()
    bfs_queue.clear()
    bfs_queue.appendleft(start_point)
    area_size = 0
    while len(bfs_queue) > 0:
        x, y = bfs_queue.pop()
        area_size += 1
        print(x, y, area_size)
        for dx, dy in [(0,1), (1,0), (0,-1), (-1,0)]:
            if (x + dx, y + dy) in total_points:
                bfs_queue.appendleft((x+dx,y+dy))
                total_points.discard((x+dx,y+dy))
    area_sizes.append(area_size)
for idx, area_size in enumerate(sorted(area_sizes)):
    if idx == 0:
        print(area_size, end="")
    else:
        print(" ", area_size, end="")

