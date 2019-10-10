#!/bin/python3

import math
import os
import random
import re
import sys



# The bigSorting function.
def bigSorting(unsorted):
    return sorted(sorted(unsorted), key=len)



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    unsorted = []

    for _ in range(n):
        unsorted_item = input()
        unsorted.append(unsorted_item)

    result = bigSorting(unsorted)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
