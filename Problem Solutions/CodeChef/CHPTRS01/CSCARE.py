# PASSES SUBTASK 1 in O(N^2)
t = int(input())
for _ in range(t):
    x = int(input())
    n = int(input())
    A = list(map(int, input().split()))
    m = int(input())
    B = list(map(int, input().split()))
    res = 0
    for i in range(0, m - n + 1):
        possible = True
        diff = abs(A[0] - B[i])
        if (diff > x):
            continue
        for k in range(0, n):
            if (abs(A[k] - B[i + k]) != diff):
                possible = False
                break
        if (possible):
            res += 1
    print(res)