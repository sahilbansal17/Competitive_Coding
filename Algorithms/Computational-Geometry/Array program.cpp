/*  The following program is a solution to 
    We are given a sequence a1, a2, ..., aN. We have to find the smallest possible value of ai + aj ,
    where 1 = i < j = N. We have also given the size of array.

    Exanple No. of elements 5
    {3,2,5,7,1)
    Ans 3
    HINT (2+1)
*/
//Name: Rishabh Garg
//E-mail: rishabhgarg25699@gmail.com
//TITLE:  ARRAY

#include<stdio.h>
int main()
{
    int i,j,a[100],small,n;
    //Enter the no. of elements in an array.
    scanf("%d",&n);
    //Entering the  elements in an array by for loop
    for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
    //We add first two elements and then put the value in an variable i.e small    
    small=a[1]+a[2];
    //By running two loops we are finding the smallest addition of two elements and then
    //replacing the addition value with small variable
    for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(small>(a[i]+a[j]))
                {
                    small=a[i]+a[j];
                }
            }
        }
    //After running both loops we have a smallest addition of two variables 
    //in small variable.Now we print this value.
        printf("%d\n",small);
    return 0;
}
 
 
//As this program has two loops running correspondingly so time complexity of 
//this program is n*n=O(n^2)
// - Output Size: 128.1015625 KiB
// - Compilation Time: 5.78s