// This program addresses the famous, Travelling Salesman Problem:
// Probem Statement: Given a set of cities and distance between every pair of cities, 
// 				  the problem is to find the shortest possible route that visits every 
// 				  city exactly once and returns to the starting point.
// Input Format : The first line contains n,the number of cities in the region. (1 <= n <=20 (Explained Below))
// 			   Each of the next n lines contain n numbers describing the distance matrix.
// 			   (The distance from a city to itself is taken as zero)
// Output Format: A single number , the length of the shortest such path.

// Approach Used : Dynamic Programming, Bit Masking

// Intuition for using Bit masking:
// The bitmasking technique is used to keep track of the cities visited so far.
// Say for example there are 4 cities and after certain steps cities B,D are visited only.
// At this instant the variable mask would appear as 1010 as the MSB signifies that city D has been visited
// and the LSB signifies that city A is not yet visited and so on. Now suppose if we carry out an AND operation as
// 1010 & 0010(for City B) , the result is non zero if City B has been already visited and zero if City B
// is not yet visited(1000 & 0010). This approach is used to continue the recursion. Bit masking + the current city position
// uniquely specifies the subproblem for the main-problem. 


//Author : monsijb


#include<iostream>
using namespace std;

int n;
int dp[1048576][20];
int dist[20][20];
int visited_all;

// A function to calculate (base)^(exponent) noting that pow gives error at high values.
int power(int base,int exp)
{
	int result = 1;
	for(int i=1; i<=exp; i++)
	{
		result = result * base;
	}
	return result;
}

// Function to initialize dp array
void init(int n)
{
	for(int i=0; i<(1<<n); i++)
	{
		for(int j=0; j<n; j++)
		{
			dp[i][j]=-1;
		}
	}
}

// Recursive function to calculate the final result
int tsProblem(int mask,int position)
{
	// Base condition
	if(mask==visited_all)
		return dist[position][0];
	
	// lookup in dp array to check if this has already been calculated
	if(dp[mask][position]!=-1)
		return dp[mask][position];
	
	int ans = INT_MAX;
	for(int city=0; city<n; city++)
	{
		if((mask & (1<<city))==0)
		{
			int new_cost = dist[position][city] + tsProblem((mask|(1<<city)),city);
			ans = min(new_cost,ans);
		}
	}
	return dp[mask][position] = ans;
}

int main()
{
	cout << "Enter the number of cities in the region: ";
	cin >> n;
	
	visited_all =(1<<n)-1;
	
	//Initialization of dp array
	init(n);
	
	cout << "\nEnter the distance matrix: \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> dist[i][j];
		}
	}
	
	cout << "\nMinimum possible distance: "<<tsProblem(1,0) << "\n";
	return 0;
}



// Time Complexity Analysis:O( (n*n) * (2^n) )
// It is clear that at each stage of the problem there can be a maximum n * (2^n) subproblems, with each taking O(n) time to compute.
// So the overall time complexity is O( (n*n) * (2^n) ) . This is very less than that of the brute approach i.e O(n!). However this
// approach is not suitable for very high values of n either. It is due to the size constraint of the 2d dp array. The maximum number of
// cities can be taken 22 . So 20 can be taken as a safe limit. (Maximum global array size : 10^9).


// Space Complexity Analysis:O( n * (2^n) )
// The size of the auxiliary dp array increases exponentially with n(the number of cities). So the order of space complexity
// is exponential.
