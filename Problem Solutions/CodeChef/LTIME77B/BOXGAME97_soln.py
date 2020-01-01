import sys

if __name__ == '__main__':
    t = int(input())
    while t:
        n, k, p = map(int, input().split())
        a = [int(_) for _ in input().split()]

        if k % 2 != 0:
            if p == 0:
                print(max(a))
            else:
                print(min(a))
        else:
            if p == 0:
                mx = max(a[1], a[n-2])
                for i in range(1, n-1):
                    mx = max(mx, min(a[i-1], a[i+1]))

                print(mx)
            else:
                mn = min(a[1], a[n-2])
                for i in range(1, n-1):
                    mn = min(mn, max(a[i-1], a[i+1]))

                print(mn)

        t -= 1

# Some Edges Cases

# 7 4 1
# 2 4 3 2 3 4 1

# 6 4 0
# 1 3 1 1 2 1

# 7 4 0
# 2 4 3 2 3 4 2
