t = int(input())

for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    nums = sorted(nums)
    res = nums[1] - nums[0]
    for i in range(1, n - 1):
        res = min(res, nums[i + 1] - nums[i])
    print(res)