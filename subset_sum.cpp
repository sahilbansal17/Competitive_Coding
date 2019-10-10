/*
 * Author :- Divyesh Srivastava
 * Institute :- National Institute of Technology, Meghalaya
 
                        <-- Subset Sum Problem using Dynamic Programming ( DP ) -->
*/



/* An array a[] of size n is given and a value x is given, we have to check whether any subset form by given have sum equal to x.
 * We are using Dynamic Programming approach in CPP Programming Language to solve this Problem */


#include<iostream>
using namespace std;

void solve(int a[], int n, int x)
{
	int i,j;

	int dp[n+1][x+1];  // 2-D DP of (array_size+1 *  x+1)

	for(i=0;i<=n;i++)  // If sum is 0, then result will be true (1)
		dp[i][0]=1;

	for(j=1;j<=x;j++)  // If set is empty, then result will be false (0)
		dp[0][j]=0;

	for(i=0;i<=n;i++)   // Filling DP in bottom up manner

	{
		for(j=1;j<=x;j++)

		{
			if(j<a[i])  // Current element is greater than j
				dp[i][j]=dp[i-1][j];   // Current element can not be included to give a sum equal to j.

			else
				dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]]; // Current element can be included to give sum j OR cannot be included
		}
	}

	if(dp[n][x]==1) // We can get sum by subset formed from given array a[]
		cout<<"Possible"<<endl;

	else
		cout<<"Not Possible"<<endl;
}

int main()
{
	int n;
	cin>>n; // Size of array

	int a[n];

	for(long i=0;i<n;i++)
	{
		cin>>a[i];  // Taken input an array of size n
	}

	int x;
	cin>>x;           // Sum value which we need to check in array

	solve(a,n,x);     // Function to check whether any subset from given array can add upto give sum 
}


                                       /*   Time Complexity :- O(x * n)  */




























