n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
for mid in range(n):
    for start in range(n):
        for end in range(n):
            if start == mid or mid == end:
                continue
            if graph[start][mid] and graph[mid][end]:
                graph[start][end] = 1
for row in graph:
    for idx, elem in enumerate(row):
        if idx != 0:
            print(' ', end="")
        print(elem, end="")
    print()