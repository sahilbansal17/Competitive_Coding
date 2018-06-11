#only for 1st and 2nd subtask
def get_all_substrings(string):
    length = len(string)
    for i in range(length):
        for j in range(i + 1, length + 1):
            yield(string[i:j]) 
a=list(get_all_substrings(input()))
a.sort()
x="".join(a)
g=0
t=int(input())
for q in range(t):
    p,m=[int(e) for e in input().split(" ")]
    k=int((p*g)%m)
    print(x[k])
    g+=ord(x[k])
