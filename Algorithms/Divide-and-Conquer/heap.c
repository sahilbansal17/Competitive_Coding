#include <stdio.h>
#include<malloc.h>
/*Name - Jyoti Mishra (jstjyoti)
Email-jyotimishra29091997@gmail.com
Heap-Sort (Divide and Conquer) 
INTRODUCTION :  
a. Definition of a complete Binary Tree: A  Tree is said to be complete binary tree if all it's levels have maximum number of nodes(two for each parent) except possibly the last level and 
all the nodes in the last level appear as per left as possible. 
b. Heap: A Heap is a Complete Binary Tree which is implemented using an array(Linear Data Structure). 
Max Heap: A heap is called max heap if all the nodes having a value greater than every children of the node. 
This is used for Sorting in Ascending Order. 
Min Heap: a heap is called min heap if all the nodes having smaller value than every children of the node '''
*/
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
/*This function is for swapping two values having Time Complexity O(1) and space Complexity O(1) as only one estra pointer required to swap values*/
void heap(int *arr, int n, int i)
{
    int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 	if (l < n && *(arr+l) >*(arr+largest))
        largest = l;
 	if (r < n && *(arr+r) > *(arr+largest))
        largest = r;
   if (largest != i)
    {
        swap((arr+i), (arr+largest));
        heap(arr, n, largest);
    }
}
/*This(above) function is responsible for creation a max heap everytime when it is called .
Space Complexity of this is O(1) as only a few single variables are needed and they together represent a constant number of extra variables
Time Complexity of above funtion is O(Logn) as the task is divided into two equal halves T(n)=T(Height as we are taking one of lest and right subtrees to adjust the tree structure)
height of tree having n nodes=Logn
*/
void heapSort(int *arr, int n)
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        heap(arr, n, i);
    for (i=n-1; i>=0; i--)
    {
      
        swap((arr+0), (arr+i));
 		heap(arr, i, 0);
    }
}
/*This Function is Fuction for Calling Heap method and causing sort by each time removing last element after first and last elements are swapped.
Space complexity of this is O(1) as each time only some constant number of Variables are needed.
Time Coomplexity is O(nLogn) as it is calling heap function from an i loop having iteration n times(below i loop)
above i loop has iterartions lesser than n times so it is having complexity<O(nLogn)
Therefore, Time Complexity is O(nLogn)
*/
void display(int *arr, int n)
{
	int i;
    for (i=0; i<n; ++i)
        printf("%d\t",*(arr+i));
    printf("\n");
}
 /*This Function is only for Displaying array*/
int main()
{
    int *arr,i,n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	arr=(int *)malloc(n*(sizeof(int)));
	printf("Enter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	 heapSort(arr, n);
 	 printf("Sorted array is : ");
    display(arr, n);
	return 0;
}
/*in Main we take input number of elements and unsorted array and call function to sort the array and display*/
