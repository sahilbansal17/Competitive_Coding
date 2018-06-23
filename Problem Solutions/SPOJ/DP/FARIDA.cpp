#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long n;
	long long arr[1000100];
	long long dp[10000100];

	// Taking input the number of test cases
	cin>>t;

	for(int i=1;i<=t;i++)
	{
		// Taking input the number of monsters
		cin>>n;

		for(int j=0;j<n;j++)
		{
			// Taking input the number of coins the (j+1)th monster has.
			cin>>arr[j];
		}

		// Making initial optimal choices.
		dp[0] = arr[0];
		dp[1] = max(arr[0], arr[1]);
		
		for(int j=2;j<n;j++)
		{

			/*
				Getting the maximum amount of coins. For this two choices have to be considered. 
				1. Consider taking the coins from the current monster and the monster standing 2 steps back to the current monster.
				   We are doing so because we can take coins only from alternate monsters.
				2. Consider taking the coins from the monster which is standing 1 step back from the current monster.
			*/
			dp[j] = max(arr[j]+dp[j-2], dp[j-1]);
		}
		
		// Printing the output as per the output specifications.
		cout<<"Case "<<i<<": "<<dp[n-1]<<endl;
	}
	return 0;
}