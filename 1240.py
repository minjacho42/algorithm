import heapq

N, M = map(int, input().split())
graph = [[-1] * (N + 1) for _ in range(N + 1)]
for _ in range(N - 1):
    node1, node2, cost = map(int, input().split())
    graph[node1][node2] = cost
    graph[node2][node1] = cost
for _ in range(M):
    node1, node2 = map(int, input().split())
    que = []
    costs = [-1 for _ in range(N + 1)]
    for i in range(1, N + 1):
        if graph[node1][i] > 0:
            heapq.heappush(que,(graph[node1][i], i))
    while len(que) > 0:
        cost, node_idx = heapq.heappop(que)
        if node_idx == node2:
            print(cost)
            break
        for i in range(N + 1):
            if graph[node_idx][i] > 0:
                if costs[i] >= 0 and costs[i] <= graph[node_idx][i] + cost:
                    continue
                else:
                    costs[i] = graph[node_idx][i] + cost
                    heapq.heappush(que,(costs[i], i))
