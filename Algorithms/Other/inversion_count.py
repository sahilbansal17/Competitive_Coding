from sortedcontainers import SortedList

'''
Given an array A, a pair (i,j) is called a inversion pair if:
1) i < j
2) A[i] > A[j]
'''

'''
The below mentioned algorithm finds the number of inversion pairs in a array 'arr' of 
size 'n' with  O(nlogn) time complexity and O(n) space complexity.
The approach is based on:
For any index 'i' the number of elements in 'arr[i+1:n]' smaller than 'arr[i]' will form
inversion pairs with 'i'. Now to find the number of elements in 'arr[i+1:n]' smaller than
'arr[i]' would take O(n) time by using a simple loop but that would make the time complexity
O(n^2). So, to find the required number of elements in O(logn) time, we use a SortedList(which works 
analogous to a multiset(C++) in this case) to keep the elements in 'arr[i+1:n]' in sorted order
and then apply lower_bound on them to get the number of elements smaller than 'arr[i]'
'''

'''
Link to a problem involving inversion count:
https://www.spoj.com/problems/INVCNT/
Here's a different approach to the same problem using Merge Sort:
https://www.hackerrank.com/challenges/ctci-merge-sort/problem
'''

def inversion_count(arr: list, n: int) -> int:
	b = SortedList()
	count = 0
	
	for i in range(n-1, -1, -1):
		pos = b.bisect_left(arr[i])
		count += pos
		b.add(arr[i])

	return count

def main():
	n = int(input()) #the size of the array

	arr = list(map(int, input().strip().split())) #the array

	print (inversion_count(arr, n))

if __name__ == "__main__":
	main()
