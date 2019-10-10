// Name: Ayus Das
//Email: ayusdas2000@gmail.com
/*This is a program of sorting. The sorting algorithm 
 *used here is insertion sorting. Array elements are taken
 *by user as input
*/
#include <stdio.h> 

//Function to swap the elements  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

//Function for selection sort  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
  
 
  
// Driver program to test above functions  
int main()  
{  
    int number_of_elements;
	printf("Enter the size of the array: \n");
	scanf("%d",&number_of_elements);
	int array_unsorted[number_of_elements];
	int i;
	printf("Enter the array elements: \n");
	for(i=0;i<number_of_elements;i++)
	{
		scanf("%d",&array_unsorted[i]);
	 }   
    selectionSort(array_unsorted, number_of_elements);        
    printf("Sorted array is : \n");
	for(i=0;i<number_of_elements;i++)
	{
		printf("%d  ",array_unsorted[i]);
	  }  
    return 0;  
}  
