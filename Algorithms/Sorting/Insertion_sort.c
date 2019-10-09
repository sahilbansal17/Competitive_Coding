// Name: Ayus Das
//Email: ayusdas2000@gmail.com
/*This is a program of sorting. The sorting algorithm 
 *used here is insertion sorting. Array elements are taken
 *by user as input
*/
#include <stdio.h> 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
 

  
/* Driver code */
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
  
    insertionSort(array_unsorted, number_of_elements);  
    printf("Sorted array is : \n");
	for(i=0;i<number_of_elements;i++)
	{
		printf("%d  ",array_unsorted[i]);
	  }  
  
    return 0;  
}  
