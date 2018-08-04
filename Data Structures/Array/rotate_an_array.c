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
	int i, j, p, temp;
	printf("Enter how many elements to be stored in an array\n");
	scanf("%d",&n);
	printf("Now enter all the elements in the array\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter how much do you want to left rotate the array\n ");
	scanf("%d",&rotations);
	//The below function has the main logic of the program.In this we have to find GCD.
	//The purpose of finding of GCD is that when we got the n and rotations, then we calculate the 
	//GCD of the both the numbers.Then that array will broke into groups of size no. equal to GCD.
	//This GCD helps to minimize the comparison within the array.The temination condition came when
	//GCD goes down to 1.If GCD is one then elements will be moved within their small patch.
	//With the help of GCD, elements jumps directily leaving rotation variable in one loop.
	//By this way also,this method decreases the time complexity also. 
	for (i = 0; i < gcd(rotations, n); i++)       
           {                                          
      	       temp = arr[i];                           
               j = i;                                 
               while(1)              						
                 {
                     p = j + rotations;
                     if (p >= n)
                     {
                          p = p - n;
                     }
                     if (p == i)
                          break;
                     arr[j] = arr[p];
        	     j = p;
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
//GCD function has O(log n) time complexity but time complexity of printing function of O(n)
//and we have to take the maximum time complexity and we also know that (O(log n)<O(n)).So  
// TIME COMPLEXITY OF PROGRAM = O(N) , where n is the size of array
//SPACE COMPLEXITY = O(1)
