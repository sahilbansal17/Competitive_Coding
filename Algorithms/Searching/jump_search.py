# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find the element in the array using jump search

# Code
import math

def jump_search(arr, x):
    n = len(arr)
    # size of block to be skipped
    m = math.sqrt(n)

    block = 0;
    while arr[int(min(step, n)-1)] < x:
        block = m;
        m = m + math.sqrt(n)
        if block >= n:
            return -1

    while arr[int(block)] < x:
        block = block + 1

        if block == min(m, n):
            return -1

    if arr[int(block)] == x:
        return block
    return -1

# Test-Case
arr = [0, 1, 3, 6, 7, 11, 14, 17, 19, 23, 25, 100, 2657]
x = 23

result = jump_search(arr, x)

if position == -1:
    print("The element is not present in the array")
else:
    print("The element is present at position ", position)

#Time-Complexity
# O(sqrt(n))

#Space-Complexity
# O(1)

