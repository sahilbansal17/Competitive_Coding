#!/bin/python3

import math
import os
import random
import re
import sys

"""
    Iqrar Agalosi Nureyza (@Iqrar99)

    This program is to find correct position so left total and right total 
    from the position that we found before are same.
"""


# function to search possible position 
def balancedSums(arr : list, cumulative_left : list, cumulative_right : list):
    found = "NO"
    
    # we only need Linear Search O(N) since the maximum constraint is
    # T x n = 10^6

    if len(arr) != 1:
        for i in range(0, len(arr)):
            if i == 0:
                if (0 == cumulative_right[i + 1]):
                    found = "YES"
                    break

            elif i == len(arr)-1:
                if (cumulative_left[i - 1] == 0):
                    found = "YES"
                    break

            elif (cumulative_left[i - 1] == cumulative_right[i + 1]):
                found = "YES"
                break
                
    # if we have 1 element only, then the answer must be YES,
    # because the left total and right total is zero
    else:
        found = "YES"

    return found


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        # calculate the cumulative totals from left and right
        cumulative_left = [0] * n
        cumulative_right = [0] * n
        
        cumulative = 0
        for i in range(n):
            cumulative += arr[i]
            cumulative_left[i] = cumulative

        cumulative = 0
        for i in range(n-1,-1,-1):
            cumulative += arr[i]
            cumulative_right[i] = cumulative

        result = balancedSums(arr, cumulative_left, cumulative_right)

        #print(cumulative_left)
        #print(cumulative_right)

        fptr.write(result + '\n')

    fptr.close()
