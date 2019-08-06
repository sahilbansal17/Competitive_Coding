# Minimum and Maximum
# https://www.codechef.com/JULY19A/problems/MMAX

t = int(input())

for i in range(t):
  n = int(input())
  k = int(input())

  rem = k % n
  if (n - rem == rem):
    ans = 2*min(rem, n - rem) - 1
  else:
    ans = 2*min(rem, n - rem)
  print(ans)