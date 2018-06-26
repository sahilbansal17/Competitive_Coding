// Program to find Longest Common Subsequence between two strings
// using Dynamic Programming Approach.

// Author: Pritam Negi.

#include<bits/stdc++.h>
using namespace std;

// Declaration of global variables
// Program supports two string of upto 10000 characters.
// 2D Array c is used to store the length of LCS
// 2D Array b stores the direction of tracing the array c at a particular point to find the LCS.
int i, j, m, n, c[10010][10010];
char b[10010][10010];
string x, y;

// Function to print the LCS after building of (m+1) * (n+1) matrix
void printLCS(int i,int j)
{
	if(i==0 || j==0)
	{
		return;
	}
	// Firstly recursively calling the printLCS function until
	// no diagonal direction is encountered and then printing the LCS
	if(b[i][j]=='d')
	{
		printLCS(i-1,j-1);
		cout<< x[i-1];
	}
	// Moving to the cell above to the current cell on encountering up (u) direction
	// in array b
	else if(b[i][j]=='u')
	{
		printLCS(i-1,j);
	}
	// Moving to the cell left of the current cell on encountering left (l) direction
	// in array b
	else
	{
		printLCS(i,j-1);
	}
}

// Function to find the LCS using memoization technique
void lcsMemo()
{
	// Getting the lengths of two strings
	m = x.length();
	n = y.length();

	// Setting elements of first column to 0
	for(i=0; i <= m; i++)
	{
		c[i][0] = 0;
	}

	// Setting elements of first row to 0
	for(i=0; i<=n; i++)
	{
		c[0][i] = 0;
	}

	// Updating the length in each cell of array c depending on the
	// characters encountered in both strings x and y.
	for(i=1; i<= m; i++)
	{
		for(j=1; j<=n; j++)
		{
			// If both characters match then length is incremented by 1
			// Direction of tracing is set as 'd' i.e. diagonal.
			if(x[i-1]==y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'd';
			}

			// If length in the cell above to the current cell
			// is greater than the length value present in the left cell 
			// then length from cell present above is copied
			// and direction of tracing is set as 'u' i.e. up
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 'u';
			}

			// Else the length value is copied from the left cell
			// and direction of tracing is set as 'l' i.e. left
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 'l';
			}
		}
	}
}

int main()
{
	// Taking first string as input
	cout<< "Enter the first string: ";
	cin>> x;

	// Taking second string as input
	cout<< "Enter the second string: ";
	cin>> y;

	cout<< "The Longest Common Subsequence is: ";
	
	lcsMemo();
	printLCS(m,n);
	return 0;
}