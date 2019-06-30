# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find the element in array by insertion sort
# Code
def bubble_sort():
    arr = list()
    n1 = input("Enter the number of elements of the Array :")
    n = int(n1)
    for i in range(n):
        arr.append(int(input("Enter the number :")))
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
    for i in range(len(arr)):
        print(arr[i],"\n")

# Test-Case
arr = [1, 13, 78, 6, 45689 78, 678, 45689]
bubble_sort()

# Time-Complexity
# Worst-Case : O(n*n)
# Best-Case : O(n)

# Space-Complexity
# O(1)
