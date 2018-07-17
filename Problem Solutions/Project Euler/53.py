from math import factorial as f
import time
start = time.time()
distinct = 0
n = 23
def ncr(n,r):
    return f(n)/(f(r)*f(n-r))
for n in range(23,101):
    for i in range(0,n+1):
        if(ncr(n,i) >= 1000000):
            distinct += 1
    n += 1
end = time.time()
print "\t", distinct
print "time_taken = ", end - start
