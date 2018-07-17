import sys
import time
start = time.time()
sum = 0
for i in range(1,1000):
    if i%3==0 or i%5==0:
        sum+=i
print sum
end = time.time()
print "time_taken =",end - start
