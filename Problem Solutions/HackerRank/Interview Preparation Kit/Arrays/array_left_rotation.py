#!/bin/python3

#This is the solution to "Array: Left Rotation" problem on Hackerrank in Python3. 
#Link: https://www.hackerrank.com/challenges/array-left-rotation/problem

import math
import os
import random
import re
import sys

# Complete the rotLeft function below.
def rotLeft(a, d):
    b = a[d%len(a):]
    b += a[:d%len(a)]
    a = b
    return a

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    result = rotLeft(a, d)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()