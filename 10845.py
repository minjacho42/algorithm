import sys
graph = [[-1] * (2000 + 1) for _ in range(2000 + 1)]
n = int(input())
l_dec = list(map(int, input().split()))
r_dec = list(map(int, input().split()))

sys.setrecursionlimit(10**9)

def recur(l, r):
    global graph
    if r == n or l == n:
        return 0
    if graph[l][r] != -1:
        return graph[l][r]
    if l_dec[l] > r_dec[r]:
        graph[l][r] = recur(l, r+1) + r_dec[r]
    else:
        graph[l][r] = max(recur(l+1, r+1), recur(l+1, r))
    return graph[l][r]

def main():
    print (recur(0, 0))


if __name__ == '__main__':
    main()