def f(seq):
    return [i for (v, i) in sorted((v, i) for (i, v) in enumerate(seq))]
n=int(input())
in_arr = list(map(int,input().split()))

for i in range(n):
    in_arr[i]=-in_arr[i]

out_arr = f(in_arr)

s=0

for i in range(n):
    s+=(-in_arr[out_arr[i]])*i+1

print(s)

for i in range(n):
    print(out_arr[i]+1 ,end=' ')