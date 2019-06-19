# Name : Nabanita Dash
# Email ID : dashnabanita@gmail.com

# find the element in array by interpolation search
# Code
def interpolation_search(arr, x):
	n = len(arr)
	l = 0
	h = n - 1
	while l<= h and x >= arr[l] and x <= arr[h]:
	    if l == h:
	        if arr[l] == x:
	            return l
	        return -1
	    pos = l + int(((float(h - l)/(arr[h] - arr[l])) * (x - arr[l])))

	    if arr[pos] == x:
	        return pos

	    if arr[pos] < x:
	        l = pos + 1
	    else:
	        h = pos - 1
	return -1

# Test-Case
arr = [1, 4, 7, 9, 34, 78, 678, 45689]
x = 7
position = interpolation_search(arr, x)

if position != -1:
    print("The element is found at the position ",position)
else:
    print("The element is not found")

# Time-Complexity
# Best-Case : O(log log n)
# Worst-Case : O(n)

# Space-Complexity
# O(1)

