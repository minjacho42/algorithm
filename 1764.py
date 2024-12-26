mot_deut = set()
result = set()

n, m = list(map(int, input().split()))

for _ in range(n):
	mot_deut.add(input())

for _ in range(m):
	mot_bo_eliment = input()
	if mot_bo_eliment in mot_deut:
		result.add(mot_bo_eliment)

print(len(result))
for el in sorted(result):
	print(el)
