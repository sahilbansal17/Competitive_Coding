# gives wrong answer

import math

l = input().split()
n = int(l[0])
m = int(l[1])

a = list(map(int, input().split()))

d = a[0]/2
lcm = a[0]/2

n = len(a)

def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)

for i in range(1, n):
    d = gcd(lcm, a[i]/2)
    lcm = ((a[i]/2) * lcm)/d

multiples = m//lcm
odd_multiples = math.ceil((1.0*multiples)/2)
print(odd_multiples)