# import inbuilt standard input output  
from sys import stdin, stdout 
import sys
from math import *

# For getting input from input.txt file 
stdin = open('/Users/sahilbansal/Desktop/input.txt', 'r')  
  
# Printing the Output to output.txt file 
stdout = open('/Users/sahilbansal/Desktop/output.txt', 'w') 

n, m = map(int, stdin.readline().split())

g = []

for i in range(n):
    x = stdin.readline()
    g.append(x)

# print(g[0][1], g[1][0])

q = int(stdin.readline())

qs = list(map(int, stdin.readline().split()))


steps_row = [[0 for i in range(m + 2)] for j in range(n + 2)]
steps_tot = [[0 for i in range(m + 2)] for j in range(n + 2)]

# print("steps_row:")
# print(steps_row)

# print("steps_tot:")
# print(steps_tot)

char_check_row = 0
for i in range(1, n + 1):
    char_check_col = char_check_row
    for j in range(1, m + 1):
        # print(i, j)
        # print(steps_row[i][j])
        steps_row[i][j] = steps_row[i][j - 1]
        if (char_check_col != int(g[i - 1][j - 1])):
            steps_row[i][j] += 1
        # flip
        char_check_col = char_check_col ^ 1
    # flip
    char_check_row = char_check_row ^ 1

for i in range(1, n + 1):
    for j in range(1, m + 1):
        steps_tot[i][j] = steps_tot[i - 1][j] + steps_row[i][j]

# returns the number of steps 
# to convert into chessboard
# a grid having start cell as (i, j)
# and end cell as (i + p - 1, j + p - 1)
def get_steps(i, j, p):
    steps = 0
    # if (i + p - 1 > n or j + p - 1 > m):
    #     return 10000000000
    steps += steps_tot[i + p - 1][j + p - 1]
    steps -= steps_tot[i + p - 1][j - 1]
    steps -= steps_tot[i - 1][j + p - 1]
    steps += steps_tot[i - 1][j - 1]
    return steps

min_steps = [int(10000000000)] * 210

# print("steps_row:")
# for i in range(n + 2):
#     print (steps_row[i])

# print("steps_tot:")
# for i in range(n + 2):
#     print (steps_tot[i])

for p in range(1, n + 1):
    for i in range(1, n - p + 2):
        for j in range(1, m - p + 2):
            # (i, j) is the start cell
            steps = get_steps(i, j, p)
            if (steps >= 0 and steps < min_steps[p]):
                min_steps[p] = steps
            if (p*p - steps >= 0 and p*p - steps < min_steps[p]):
                min_steps[p] = p*p - steps

# print("min_steps: ", min_steps[1:n + 1])

# print("ans:")

for c in qs:
    for p in range(200, 0, -1):
        if (min_steps[p] <= c):
            ans = p
            break
    print(ans)
