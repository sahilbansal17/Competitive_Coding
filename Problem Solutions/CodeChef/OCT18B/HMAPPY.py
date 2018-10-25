# import inbuilt standard input output  
from sys import stdin, stdout 
import sys
from math import *

# For getting input from input.txt file 
# stdin = open('/Users/sahilbansal/Desktop/input.txt', 'r')  
  
# Printing the Output to output.txt file 
# stdout = open('/Users/sahilbansal/Desktop/output.txt', 'w') 

n, m = map(int, stdin.readline().split())

a = list(map(int, stdin.readline().split()))
b = list(map(int, stdin.readline().split()))

low = 0
high = int(2e18)

c = [None]*100000
for i in range(n):
	c[i] = a[i]*b[i]

def req(cost):
	total = 0
	for i in range(n):
		if (cost >= c[i]):
			continue
		x = ceil(a[i] - cost/b[i])
		if (c[i] - x*b[i] > cost):
			x += 1
		if (x > 0):
			total += x
		# print("cost:", cost)
		# print("b[i]:", b[i])
		# print("floor:", floor(cost/b[i]))
		# print("x:", x)
	return total 

# iter = 0
while (low <= high):
	mid = (low + high) >> 1
	if (req(mid) <= m):
		high = mid - 1
		ans = mid
	else:
		low = mid + 1
	# iter += 1
	# if (iter > 100):
	# 	break
	# print("low:", low, "high:", high)
	# print("req:", mid, ":", req(mid), "\n")

print(ans)