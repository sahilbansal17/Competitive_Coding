def IsPalindrome(n):
	myStr = str(n)
	if myStr == myStr[::-1]:
		return 1
	else:
		return 0
import time

tStart = time.time()
nResult = 0
for i in range(100,1000):
    for j in range(100,1000):
	if IsPalindrome(i*j) == 1 and (i*j) > nResult:
	    nResult = (i*j)
print "Winner = " + str(nResult)
print "run time = " + str((time.time() - tStart))
