# cook your dish here
test = int(input())
while test:
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    score = []
    for i in range(0, n):
        k = 20*a[i] - 10*b[i]
        score.append(k)
        if k < 0:
            score[i] = 0
    print(max(score))
    test -= 1