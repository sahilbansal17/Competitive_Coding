if __name__ == '__main__':
    t = int(input())

    while t != 0:
        n, k = map(int, input().split())
        arr = [int(_) for _ in input().split()]
        mid = int(n / 2)

        if k > 3 * n:
            mx = (k % (3 * n))
        else:
            mx = k

        mx2 = int(n / 2) + 1
        for i in range(mx):
            arr[i % n] = (arr[i % n]) ^ (arr[n - (i % n) - 1])
            if n % 2 != 0 and i < mx2 and k > 3 * n:
                arr[mid] = 0

        print(*arr)

        t -= 1
