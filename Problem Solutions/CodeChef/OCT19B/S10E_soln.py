if __name__ == '__main__':
    t = int(input())
    while t != 0:
        n = int(input())
        x = [int(_) for _ in input().split()]

        good = 0
        for i in range(len(x)):
            a = i-5
            if a < 0:
                a = 0

            seq = x[a:i]
            if seq:
                mx = min(seq)
                if x[i] < mx:
                    good += 1
            else:
                good += 1

        print(good)

        t -= 1
