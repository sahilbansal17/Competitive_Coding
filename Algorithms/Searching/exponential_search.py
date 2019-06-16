# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find the element in array by exponential search
# Code
def binary_search(arr, l, r, x):
	if r >= l:
		mid = l + (r-l)/2

		if arr[mid] == x:
			return mid

		if arr[mid] > x:
			return binary_search(arr, l, mid - 1, x)

		return binary_search(arr, mid + 1, r, x)
	return -1

def exponential_search(arr, x):
	n = len(arr)

	if arr[0] == x:
		return 0

	i = 1
	while i < n and arr[i] <= x:
		i = i*2

	return binary_search(arr, i/2, min(i, n), x)


# Test-Case
arr = [1, 4, 7, 9, 34, 78, 678, 45689]
x = 7
position = exponential_search(arr, x)

if position != -1:
    print("The element is found at the position ",position)
else:
    print("The element is not found")

# Time-Complexity
# Best-Case : O(log n)
# Worst-Case : O(1)

# Space-Complexity
# O(1)
