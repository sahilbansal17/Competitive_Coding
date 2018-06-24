##Name - Jyoti Mishra (jstjyoti)
##Email-jyotimishra29091997@gmail.com
'''Heap-Sort (Divide and Conquer) 
INTRODUCTION :  
a. Definition of a complete Binary Tree: 
A  Tree is said to be complete binary tree if all it's levels have maximum 
number of nodes(two for each parent) except possibly the last level and 
all the nodes in the last level appear as per left as possible. 

b. Heap: 
A Heap is a Complete Binary Tree which is implemented using an 
array(Linear Data Structure). 
Max Heap: A heap is called max heap if all the nodes having a value 
greater than every children of the node. 
This is used for Sorting in Ascending Order. 
Min Heap: a heap is called min heap if all the nodes having smaller 
value than every children of the node '''
# Python program for implementation of heap Sort
# To  makeheap btree rooted at index i.
# n is size of heap
def makeheap(arr, n, i):
    largest = i  # Initialize largest as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2
    # See if left child of root exists and is
    # greater than root
    if l < n and arr[i] < arr[l]:
        largest = l
    # See if right child of root exists and is
    # greater than root
    if r < n and arr[largest] < arr[r]:
        largest = r
    # Change root, if needed
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]  # swap
        # Heapify the root.
        makeheap(arr, n, largest) 
# The main function to sort an array of given size
def heapSort(arr):
    n = len(arr)
    # createAndBuildHeap() Build a maxheap.
    for i in range(n, -1, -1):
        makeheap(arr, n, i)
   # One by one extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]   # swap
        makeheap(arr, i, 0)
 # Driver code to test above
arr=eval(input("Enter the List of unsorted elements"))
heapSort(arr)
n = len(arr)
print ("Sorted array is")
for i in range(n):
    print ("%d" %arr[i]),
'''Time complexity of makeheap is O(Logn). Time complexity of for loop in heap sort
is O(n) and overall time complexity of Heap Sort is O(nLogn).In all cases best ,Worst and 
average  it has complexity O(nlogn)'''
'''Space Complexity of heapsort is O(1) '''
#code is contibuted By Jyoti Mishra(@jstjyoti)
