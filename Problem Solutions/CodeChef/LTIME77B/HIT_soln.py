if __name__ == '__main__':
    t = int(input())
    while t:
        n = int(input())
        x = [int(_) for _ in input().split()]
        x.sort()

        ans = []
        a = (n // 2) // 2
        if x[a] != x[a - 1]:
            ans.append(x[a])
            b = 2 * a
            if x[b] != x[b - 1]:
                ans.append(x[b])
                b += a
                if x[b] != x[b - 1]:
                    ans.append(x[b])

                    print(*ans)
                else:
                    print(-1)
            else:
                print(-1)
        else:
            print(-1)

        t -= 1
