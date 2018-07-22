//Name = Rishabh Garg
//E-mail = rishabhgarg25699@gmail.com
//******* PROGRAM TO ROTATE AN ARRAY OF SIZE N BY ROTATIONS ELEMENTS *********
//********************* Program in C Language ********************************
//This program can be done by thee methods with different time and space complexities. 
//This program is in the best complexity of all the programs.This is done with the help of GCD.

#include <stdio.h>
int gcd(int , int );
int main()
{
	int arr[50],rotations,n;
	int i, j, k, temp;
	printf("Enter how many elements to be stored in an array\n");
	scanf("%d",&n);
	printf("Now enter all the elements in the array\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter how much do you want to left rotate the array\n ");
	scanf("%d",&rotations);
	for (i = 0; i < gcd(rotations, n); i++)       //The real purpose of GCD is that it gives
           {                                          //the actual rotation of an array.
      	       temp = arr[i];                         //It minimises some rotation.It is calculated  
               j = i;                                 //through function in this program.
               while(1)              						
                 {
                     k = j + rotations;
                     if (k >= n)
                     {
                          k = k - n;
                     }
                     if (k == i)
                          break;
                     arr[j] = arr[k];
        	     j = k;
      	         }
               arr[j] = temp;
            }
  	for (i = 0; i < n; i++)                        //Printing the modified array
           printf("%d\t",arr[i]);
}
//Recursive Function to calculate GCD
int gcd(int p,int q)
{
   if (q==0)                                          //Base Case
     return p;
   else
     return gcd(q, p%q);                             //Recursive Function
}

// TIME COMPLEXITY = O(N) , where n is the size of array
//SPACE COMPLEXITY = O(1)
