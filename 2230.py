N, M = list(map(int, input().split()))
nums = []
for _ in range(N):
    nums.append(int(input()))

i, j = 0, 1
nums.sort()
answer = nums[len(nums) - 1] - nums[0]
while i < j < N:
    if nums[j] - nums[i] > M:
        answer = answer if nums[j] - nums[i] > answer else nums[j] - nums[i]
        i += 1
        if i == j:
            j += 1
    elif nums[j] - nums[i] < M:
        j += 1
    else:
        answer = M
        break
print(answer)