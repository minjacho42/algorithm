n = int(input())
nums = list(map(int, input().split()))
lis = []
lis.append(nums[0])

def binary_search(nums, target):
	start, end = 0, len(nums)
	while start < end:
		mid = (start + end) // 2
		if nums[mid] < target:
			start = mid + 1
		else:
			end = mid
	return start


for num in nums[1:]:
	idx = binary_search(lis, num)
	if idx == len(lis):
		lis.append(num)
	else:
		lis[idx] = num

print(len(lis))
