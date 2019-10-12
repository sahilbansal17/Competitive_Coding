#!/bin/python3

import math
import os
import random
import re
import sys

"""
    Iqrar Agalosi Nureyza (@Iqrar99)

    We want to know how many words in string S. So we must count all uppercase
    characters in String s
"""

# this function is to count all uppercase characters
def camelcase(s : str):
    answer = 0

    for i in range(len(s)):
        if s[i].upper() == s[i]:
            answer += 1

    # Since the first character in String s is in lowercase, so we sum it with 1
    return answer + 1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = camelcase(s)

    fptr.write(str(result) + '\n')

    fptr.close()
