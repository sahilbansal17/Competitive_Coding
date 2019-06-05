# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# Find an element in an array using linear search

# Code
def linear_search(arr, x):
    n = len(arr)
    for i in range (0, n):
        if (arr[i] == x):
            print("The element is found at the position ",i)
    print("The element is not present in the array")

# Test-Case
arr = [34, 56, 51, 980, 67838, 4, 07, 17]
x = 07
result = linear_search(arr, x)

# Time-Complexity
# Worst Case : O(n)

# Space-Complexity
# O(1)
