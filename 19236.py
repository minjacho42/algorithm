from copy import deepcopy

directions = [(0, 0), (-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]

def get_next_point(direct, point):
    point_x, point_y = point
    direction_x, direction_y = directions[direct]
    return point_x + direction_x, point_y + direction_y

def move_fishes(fish_dict:dict, sea_map:list):
    for idx in range(1, 17):
        if not idx in fish_dict:
            continue
        direct, point = fish_dict[idx]
        for i in range(8):
            next_point = get_next_point(direct, point)
            if 0 <= next_point[0] < 4 and 0 <= next_point[1] < 4 and sea_map[next_point[0]][next_point[1]] > -1:
                fish_dict[idx] = (direct, next_point)
                target_fish_idx = sea_map[next_point[0]][next_point[1]]
                if target_fish_idx > 0:
                    prev_fish_direct, _ = fish_dict[target_fish_idx]
                    fish_dict[target_fish_idx] = (prev_fish_direct, point)
                sea_map[next_point[0]][next_point[1]] = idx
                sea_map[point[0]][point[1]] = target_fish_idx
                break
            direct += 1
            if direct > 8:
                direct -= 8

def printer(fish_dict, sea_map):
    for row in sea_map:
        print(row)
    print(fish_dict)

def dfs(fish_dict, sea_map, shark_point, shark_eat, before_shark_point):
    dfs_result_list = []
    t_fish_dict = deepcopy(fish_dict)
    t_sea_map = deepcopy(sea_map)
    eaten_fish = t_sea_map[shark_point[0]][shark_point[1]]
    t_sea_map[shark_point[0]][shark_point[1]] = -1
    if before_shark_point:
        t_sea_map[before_shark_point[0]][before_shark_point[1]] = 0
    shark_eat += eaten_fish
    shark_direction = t_fish_dict[eaten_fish][0]
    t_fish_dict.pop(eaten_fish)
    move_fishes(t_fish_dict, t_sea_map)
    # printer(t_fish_dict, t_sea_map)
    target_fish_point = (shark_point[0] + directions[shark_direction][0], shark_point[1] + directions[shark_direction][1])
    while 0 <= target_fish_point[0] < 4 and 0 <= target_fish_point[1] < 4:
        target_fish_idx = t_sea_map[target_fish_point[0]][target_fish_point[1]]
        if target_fish_idx > 0:
            dfs_result = dfs(t_fish_dict, t_sea_map, target_fish_point, shark_eat, shark_point)
            dfs_result_list.append(dfs_result)
        target_fish_point = (target_fish_point[0] + directions[shark_direction][0], target_fish_point[1] + directions[shark_direction][1])
    return max(dfs_result_list) if len(dfs_result_list) else shark_eat

if __name__ == "__main__":
    fish_dict = {}
    sea_map = [[0 for i in range(4)] for j in range(4)]
    for i in range(4):
        row = list(map(int, input().split()))
        for j in range(4):
            fish_num, fish_direct = row[j * 2], row[j * 2 + 1]
            fish_dict[fish_num] = (fish_direct, (i, j))
            sea_map[i][j] = fish_num
    # printer(fish_dict, sea_map)
    print(dfs(fish_dict, sea_map, (0, 0), 0, None))