roll = input()
devil = input()
angel = input()

devil_map = [[0 for _ in range(len(devil))] for __ in range(len(roll))]
angel_map = [[0 for _ in range(len(angel))] for i in range(len(roll))]
for i, roll_alpha in enumerate(roll):
    for j, (d_alpha, a_alpha) in enumerate(zip(devil, angel)):
        if i == 0:
            if d_alpha == roll_alpha:
                devil_map[i][j] = 1
            if a_alpha == roll_alpha:
                angel_map[i][j] = 1
        else:
            if d_alpha == roll_alpha:
                devil_map[i][j] = sum(angel_map[i-1][:j])
            if a_alpha == roll_alpha:
                angel_map[i][j] = sum(devil_map[i-1][:j])
print(sum(devil_map[len(roll) - 1]) + sum(angel_map[len(roll) - 1]))
