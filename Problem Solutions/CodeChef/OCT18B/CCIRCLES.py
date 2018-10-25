from math import * 

n, q = map(int, input().split())

x = []
y = []
r = []
for i in range(n):
	a, b, c = map(float, input().split())
	x.append(a)
	y.append(b)
	r.append(c)

res = []
for i in range(1000010):
	res.append(0)

for i in range(n):
	for j in range(i + 1, n):
		c2c = sqrt((x[i] - x[j])**2 + (y[i] - y[j])**2)
		# print("C2C: ", c2c)
		larger_r = max(r[i], r[j])
		smaller_r = min(r[i], r[j])
		if (c2c > r[i] + r[j]):
			# circles apart from each other
			low = c2c - r[i] - r[j]
		elif (c2c <= r[i] + r[j] and c2c >= larger_r - smaller_r):
			# circles touching at one or two points
			low = 0
		elif (c2c < larger_r - smaller_r):
			# one circle inside another circle
			low = larger_r - c2c - smaller_r

		high = c2c + r[i] + r[j]

		low = ceil(low)
		high = floor(high)
		
		res[low] = res[low] + 1
		res[high + 1] = res[high + 1] - 1
		# print(low, high)

for i in range(1, 1000010):
	res[i] = res[i - 1] + res[i]

for i in range(q):
	k = int(input())
	print(res[k])