# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find an element in an array using binary search

# Code
def binary_search(arr, l, r, x):
    if r >= l:
       mid = l + (r - l)/2
       if arr[mid] == x:
           return mid
       elif arr[mid] > x:
           return binary_search(arr, l, mid-1, x)
       else :
           return binary_search(arr, mid+1, r, x)
    else:
        return -1

# Test-Case
arr  = [49, 25, 2598, 345, 8756, 98765]
x = 25

result = binary_search(arr, 0, len(arr) - 1, x)

if result != -1:
   print "Element is present at position ", result
else:
   print "Element is not present in array"

# Time-Complexity
# Worst Case : O(log n)

# Space-Complexity
# O(1)
