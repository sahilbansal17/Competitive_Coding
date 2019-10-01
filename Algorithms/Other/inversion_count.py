from bisect import bisect_left as lower_bound

'''
Given an array A, a pair (i,j) is called a inversion pair if:
1) i < j
2) A[i] > A[j]
'''

'''
The below mentioned algorithm finds the number of inversion pairs in a array 'arr' of 
size 'n' with time complexity O(nlogn) and O(n) space complexity.
Link to a problem involving inversion count:
https://www.spoj.com/problems/INVCNT/
Here's a different approach to the same problem using Merge Sort:
https://www.hackerrank.com/challenges/ctci-merge-sort/problem
'''
def inversion_count(arr: list, n: int) -> int:
	b = []
	count = 0
	
	for i in range(n-1, -1, -1):
		pos = lower_bound(b, arr[i])
		count += pos
		b.insert(pos, arr[i])

	return count



def main():
	n = int(input()) #the size of the array

	arr = list(map(int, input().strip().split())) #the array

	print (inversion_count(arr, n))

if __name__ == "__main__":
	main()
