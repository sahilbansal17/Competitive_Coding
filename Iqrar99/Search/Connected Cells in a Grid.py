#!/bin/python3

import math
import os
import random
import re
import sys

"""
    Iqrar Agalosi Nureyza (@Iqrar99)
    
    This program is to find the largest region.
    Search a value of 1, then count all adjacent cells.
"""

# This function is to search cells that containing 1,
# then compute total 1 in a region
def search(matrix : list):
    answer = 0
    
    # this search has O(N^2) complexity
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:

                # using max() to find the largest region
                answer = max(answer, count(matrix, i, j, 0))

    return answer

# This function will use Queue system to fill the region
# We use -1 as a value for a cell that has been visited
def count(matrix : list, r : int, c : int, counter : int):
    queue_x = [] 
    queue_y = []

    queue_x.append(r)
    queue_y.append(c)

    # search until there is no 1 left
    while (len(queue_x) != 0 and len(queue_y) != 0):
        pos_x = queue_x.pop(0)
        pos_y = queue_y.pop(0)

        if (pos_x >= 0 and pos_y >= 0 and pos_x < len(matrix) and pos_y < len(matrix[0])):
            if matrix[pos_x][pos_y] == 1:
                
                # mark as visited
                matrix[pos_x][pos_y] = -1

                # search horizontally and vertically

                queue_x.append(pos_x + 1)
                queue_y.append(pos_y)

                queue_x.append(pos_x - 1)
                queue_y.append(pos_y)

                queue_x.append(pos_x)
                queue_y.append(pos_y + 1)

                queue_x.append(pos_x)
                queue_y.append(pos_y - 1)

                # search diagonally

                queue_x.append(pos_x + 1)
                queue_y.append(pos_y + 1)

                queue_x.append(pos_x + 1)
                queue_y.append(pos_y - 1)

                queue_x.append(pos_x - 1)
                queue_y.append(pos_y + 1)

                queue_x.append(pos_x - 1)
                queue_y.append(pos_y - 1)

                # count this cell
                counter += 1

    return counter
                

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    m = int(input())

    matrix = []

    for _ in range(n):
        matrix.append(list(map(int, input().rstrip().split())))

    result = search(matrix)

    fptr.write(str(result) + '\n')

    fptr.close()
