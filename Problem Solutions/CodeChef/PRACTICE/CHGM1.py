t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    ans = -1000000
    cur = 0
    for i in range(0, len(nums)):
        cur += nums[i]
        if (cur > ans):
            ans = cur
        if (cur < 0):
            cur = 0
    print(ans)