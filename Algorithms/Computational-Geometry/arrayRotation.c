//Name = Rishabh Garg
//E-mail = rishabhgarg25699@gmail.com
//******* PROGRAM TO ROTATE AN ARRAY OF SIZE N BY ROTATIONS ELEMENTS *********
//********************* Program in C Language ******************************** 

#include <stdio.h>
int main()
{
	int arr[50],rotations,n,i,k;
	printf("Enter how many elements to be stored in an array\n");
	scanf("%d",&n);
	printf("Now enter all the elements in the array\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter how much do you want to left rotate the array\n ");
	scanf("%d",&rotations);
	for(k=1 ; k <= rotations ; k++)       //Loop for rotate the elements of rotation times 
	{
		 int temp;
		 temp = arr[0];                   //Store the first element of array in temp
		 int j;
  		 for (j = 0; j < n-1; j++)        //This loop rotates the array left by only one time                  
  		 {
	  		arr[j] = arr[j+1];
	  	 }
    	 arr[j] = temp;
	}
	for (i = 0; i < n; i++)               //Printing the modified array
      printf("%d\t",arr[i]);
}

// TIME COMPLEXITY = O(N*rotations)
//SPACE COMPLEXITY = O(1)

