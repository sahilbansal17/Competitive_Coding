t = int(input())

for _ in range(t):
    l = input().split()
    n = int(l[0])
    k = int(l[1])
    v = int(l[2])
    nums = map(int, input().split())
    tot = sum(nums)
    rem = (n+k)*v - tot
    if (rem > 0 and rem % k == 0):
        print(rem//k)
    else:
        print(-1)
