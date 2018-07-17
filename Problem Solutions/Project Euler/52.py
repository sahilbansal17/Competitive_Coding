import time
start = time.time() #start time
f = lambda n: sorted(str(n))

n = 9999
while not f(n) == f(2*n) == f(3*n) == f(4*n) == f(5*n) == f(6*n):
    n += 9

end = time.time() #end time

print "n = ",n
print "time taken = ", end - start
