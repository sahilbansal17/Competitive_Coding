// Name: Rishabh Garg
// Email-id: rishabhgarg25699@gmail.com
//This program is to delete the duplicate elements from an array
//either it is sorted or unsorted.

#include<stdio.h>
int main()
{
   int n, arr1[50], arr2[50], count = 0, i, j;
   printf("How many numbers do you want to store in array?\n");
   scanf("%d",&n);
   printf("Enter all numbers in the array\n");
   for(i=0;i<n;i++)
   scanf("%d",&arr1[i]);
   for(i=0;i<n;i++)                 //This for loop is for traversing the whole array      
   {                                    
      for(j=0;j<count;j++)         //This for loop is for checking the duplicate element in an array
      {
         if(arr1[i]==arr2[j])
            break;                  //If we found the duplicate element in an array then this loop will break 
      }
      if(j==count)
      {
         arr2[count] = arr1[i];     //This condition transfers the one array element into another array  
         count++;                   //element after deleting the duplicate element
      }
   }
   printf("New array after removing all duplicate elements\n");         
   for(i=0;i<count;i++)              
      printf("%d\n",arr2[i]);       //Printing the elements of new array
 
   return 0;
}

//The time complexity of this program is O(n^2) because in this program there is 
//two nested loop which gives n*n=O(n^2 ) complexity.