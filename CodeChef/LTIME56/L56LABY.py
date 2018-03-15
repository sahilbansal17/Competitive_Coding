#for subtask 1
#pyhton implementation
/*
  I used an scattering like idea:- first i assign the +ive int value to one plus that value
  and then assign the sharing side cells the one minus the int value only if the exiting value is 0 or a +ive value less than
  the one i am going to assign,
  i ran this loop till through recursion and it ends when nothing changes in the matrix for whole loop.
  after this the one which are left with 0 in them are non escapable and hence we get the answer. the only problem i was
  was that it was claculating the already calculate case in every recursion thus, got TLE for the rest cases.
*/
def function(arr,n,m,g1):
    if g1==True:
        return
    f=True
    for i in range(n):
        for j in range(m):
            if arr[i][j]>0:
                if i-1>=0:
                    if arr[i-1][j]>=0 and arr[i-1][j]<(arr[i][j]-1):
                        arr[i-1][j]=arr[i][j]-1
                        f=False
                if i+1<n:
                    if arr[i+1][j]>=0 and arr[i+1][j]<(arr[i][j]-1):
                        arr[i+1][j]=arr[i][j]-1
                        f=False
                if j-1>=0:
                    if arr[i][j-1]>=0 and arr[i][j-1]<(arr[i][j]-1):
                        arr[i][j-1]=arr[i][j]-1
                        f=False
                if j+1<m:
                    if arr[i][j+1]>=0 and arr[i][j+1]<(arr[i][j]-1):
                        arr[i][j+1]=arr[i][j]-1
                        f=False
    if f==True:
        g1=True
        return
    else:
        function(arr,n,m,g1)
def prepare(arr,n,m):
    for i in range(n):
        for j in range(m):
            if arr[i][j]>0:
                arr[i][j]+=1
    return
t=int(input())
for rrr in range(t):
    numbers=[]
    g1=False
    n,m=[int(e) for e in input().split()]
    for dd in range(n):
        numbers.append([int(e) for e in input().split()])
    prepare(numbers,n,m)
    function(numbers,n,m,g1)
    i=0
    j=0
    for i in range(n):
        for j in range(m):
            if numbers[i][j]==0:
                print("N",end="")
            elif numbers[i][j]==-1:
                print("B",end="")
            else:
                print("Y",end='')
        print()
