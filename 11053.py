n = int(input())
nums = list(map(int, input().split()))
dp = [1] * n

for i in reversed(range(n)):
	candidate = []
	for j in range(i+1,n):
		if nums[j] > nums[i]:
			candidate.append(dp[j])
	if not candidate:
		dp[i] = 1
	else:
		dp[i] = max(candidate) + 1

print(max(dp))
