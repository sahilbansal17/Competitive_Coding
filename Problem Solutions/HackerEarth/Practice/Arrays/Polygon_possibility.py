T=int(input())
a=[]
for i in range(T):
n=int(input())
list=[int(i) for i in input().split()]
a=sorted(list)
b=max(list)
c=a.pop()
s=sum(a)
if c<s:
print("Yes")
else:
print("No")
