/*
Given:
A grid of size n x m. Each cell is either Red or Blue. Red is denoted as * and . as Blue.
The entire grid is surrounded in blue.
A collection of blue cells surrounded by red on all sides is considered a pool.

Tasks:

Count the total number of pools in the grid.
Return the size of each of the pools in the grid.
Time and Space complexities for each of these operations.
Sample:
5 4

****
*..*
****
**.*
..**

Number of pools: 2; their size = 2, 1 
*/
#include <iostream>
#include <vector>
using namespace std;

// stores the input grid
vector< vector<char> > grid;
// flag to check if a location is visited
vector< vector<bool> > visited;
int n, m;

// function to check if the location can be visited
bool dangerous(int i, int j)
{
	// if location is outside the grid it can't be visited
	if(i<0 || j<0 || i>=n || j>=m)
	{
		return 0;
	}
	// if location is red coloured then it shouldn't be counted in size of pool
	// so no need to visit it
	if( grid[i][j] != '.' )
	{
		return 0;
	}
	return 1;
}
int dx[4] = { 0, 0, 1, -1} , dy[4] = { 1, -1, 0, 0};
// dfs function to find the number of connected blue cells in current pool
int dfs(int i, int j)
{
	// if node is already visited then return
	if( visited[i][j] )
	{
		return 0;
	}
	visited[i][j] = 1;
	int counter = 1;
	for (int k = 0; k < 4; ++k)
	{
		if(dangerous(i + dx[k], j + dy[k]) == 1)
		{
			counter += dfs(i+dx[k], j+dy[k]);
		}
	}
	// return total number of blue cells visited after the current cell
	return counter;
}
int main()
{
	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		grid.push_back( vector<char>() );
		visited.push_back( vector<bool>() );
		for (int j = 0; j < m; ++j)
		{
			cin >> ch;
			grid[i].push_back(ch);
			// initialising the visited vector
			visited[i].push_back(0);
		}
	}
	// As the entire grid is surrounded in blue, locations connected to points coloured blue 
	// on the boundary of grid can't be part of a pool as atleast one of the sides 
	// of this connected component will always be blue, so first mark them
	for (int j = 0; j < m; ++j)
	{
		if( visited[0][j] == 0 && grid[0][j] == '.' )
		{
			dfs(0, j);
		}
	}
	for (int j = 0; j < m; ++j)
	{
		if( visited[n-1][j] == 0 && grid[n-1][j] == '.' )
		{
			dfs(n-1, j);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if( visited[i][0] == 0 && grid[i][0] == '.' )
		{
			dfs(i, 0);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if( visited[i][m-1] == 0 && grid[i][m-1] == '.' )
		{
			dfs(i, m-1);
		}
	}
	// Now since all nodes which are blue but can't be a pool have already been marked 
	// remaining blue nodes will be part of some pool
	int counter;
	vector<int> ans;
	for (int i = 1; i < n-1 ; ++i)
	{
		for (int j = 1; j < m-1; ++j)
		{
			if( visited[i][j] == 0 && grid[i][j] == '.' )
			{
				counter = dfs(i, j);
				ans.push_back(counter);
			}
		}
	}
	cout << "Number of pools = " << int(ans.size()) << "\n";
	if(int(ans.size()) > 0)
	{
		cout<< "Size of pools = ";
		for(auto &x:ans)
		{
			cout << x << " ";
		}
	}
	cout<<"\n";
	return 0;
}
// Time complexity : Each point in the grid is visited at most once so time complexity is O(mn)
// Space complexity : We have 3 different arrays each of size n*m .So space complexity is O(mn)