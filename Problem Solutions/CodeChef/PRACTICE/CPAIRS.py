t = int(input())

for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    count_odd = 0
    res = 0
    for i in range(n - 1, 0, -1):
        if (nums[i] & 1):
            count_odd += 1
        if (not(nums[i - 1] & 1)):
            res += count_odd
    print(res)