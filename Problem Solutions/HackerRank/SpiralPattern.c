#include<stdio.h>
#include<stdlib.h>

/*This is a c program to solve the following problem,
	Print the following pattern: for any integer n(number of 	lines) input by the user
	for input n=5,
	output
	1  	2 	3 	4 	5
	16	17	18	19 	6
	15	24	25	20	7
	14	23	22	21 	8
	13	12	11	10	9

	for input n=4,
	output:
	1	2	3	4
	12	13	14	5
	11	16	15	6
	10	9	8	7

This pattern is called spiral matrix and often asked in level-0 of many competitive programming.

My approach to this problem is by selecting index of matrix in each iteration a value of track variable(here p) be stored at that place .In this manner the entire matrix will be filled .
If total number of elements (n*n) is odd(for odd values of n) the element add the centre will be updated at last for generalised simple solution*/

//Code by:Jyoti Mishra(@jstjyoti)
//Email:jyotimishra29091997@gmail.com
/*p is an integer value which keeps record of values stored in matrix a in spiral manner*/
int p=0;

/* n is input ,which stands for number of lines and elements in each line in the pattern
int n;*/

/*matrix a is the matrix having pattern stored in it .We work with matrix as directly printing the values row wise leads to so much complexity in logic*/
int a[n][n];

/*This Function Updates the matrix for forward spiral pattern as stated in the question.
Time Complexity of this Function is O(n).
Space Complexity is constant time O(1)*/

void pattern(int i,int n)
{
	int j,k,l;
	/*this loop is for updating top horizontal wall of the 	pattern(e.g. for n=5 and i=0, this fills elements, 
	 1  2  3  4  5 into the matrix)*/
	for(k=i;k<n-i-1;k++)
		a[i][k]=++p;

	/*this loop is updating right wall of the matrix depending 	upon last k value(e.g. for n=5,k becomes 4 this fills 		elements 6 7 8 9  as follows into the matrix
	1  2  3  4  5
     	*  *  *  *  6
     	*  *  *  *  7
    	*  *  *  *  8
     	*  *  *  *  9
	*=not known values yet.
	*/
	for(j=i;j<n-i-1;j++)
		a[j][k]=++p;

	/*this loop is updating right wall of the matrix 	depending 	upon last j and k value(e.g. for n=5,i=0,k 	becomes 4 and j becomes 4 	this fills elements 10 11 12 13  	as follows into the 	matrix
	1   2    3   4   5
     	*   *    *   *   6
     	*   *    *   *   7
    	*   *    *   *   8
     	13  12  11  10   9
	*=not known values yet.
	*/
	for(l=i;l<n-i-1;l++)
		a[j][k--]=++p;
	
	/*this loop is updating right wall of the matrix 	depending 	upon last j and k value(e.g. for n=5,i=0,k 	becomes 4 and j becomes 4 	this fills elements 10 11 12 13  	as follows into the 	matrix
	1    2     3   4   5
     	16   *    *   *   6
     	15   *    *   *   7
    	14   *    *   *   8
     	13  12   11  10   9
	*=not known values yet.

	*/
	for(l=i;l<n-i-1;l++)
		a[j--][k]=++p;
	/*for next value of i next (inner ) rectangle is formed      	and this manner this spiral pattern Completes*/
}

/*From main Function we call the pattern fuction for creating spiral rectngles one by one outer to inner(for n rows (int)(n/2)rectangles will be there)
 for odd numbers of n the centre value will be updated here at the end .
Final resultant matrix will also be displayed from main function .
Time Complexity of this program is O(n^2) as from main function i loop ,n times the function pattern() having time complexity O(n) is called.
Space Complexity of this program is O(n^2) as nxn matrix used for storing values
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n/2;i++)
	{
		pattern(i,n);
	}
	/*for setting centre element when there is odd number of                    	rows i.e., after filling sprial rectangles filling the  	centre element*/
	if(n%2!=0)
		a[n/2][n/2]=++p;
	
	/*This loop is for displaying the pattern of forward    	spiral*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d\t",a[i][j]);
		printf("\n");
	}
	return 0;

}

