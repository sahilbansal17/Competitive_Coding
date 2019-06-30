# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find the element in array by insertion sort
# Code
def insertion_sort(arr):
    for i in range(1, len(arr)):

        k = arr[i]
        j = i-1
        while j >= 0 and k < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = k
    for i in range(len(arr)):
        print(arr[i],"\n")

# Test-Case
arr = [1, 13, 78, 6, 45689 78, 678, 45689]
insertion_sort(arr)

# Time-Complexity
# Worst-Case : O(n*n)

# Space-Complexity
# O(1)
