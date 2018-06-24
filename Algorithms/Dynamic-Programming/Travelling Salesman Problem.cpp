/*
This program addresses the famous, Travelling Salesman Problem:
Probem Statement: Given a set of cities and distance between every pair of cities, 
				  the problem is to find the shortest possible route that visits every 
				  city exactly once and returns to the starting point.
Input Format : The first line contains n,the number of cities in the region. (1 <= n <=20 )
			   Each of the next n lines contain n numbers describing the distance matrix.
			   (The distance from a city to itself is taken as zero)
Output Format: A single number , the length of the shortest such path.

Approach Used : Dynamic Programming
Author : monsijb
*/

#include<bits/stdc++.h>
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
int tsproblem(int mask,int position)
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
			int new_cost = dist[position][city] + tsproblem((mask|(1<<city)),city);
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
	
	cout << "\nMinimum possible distance: "<<tsproblem(1,0) << "\n";
	return 0;
}
