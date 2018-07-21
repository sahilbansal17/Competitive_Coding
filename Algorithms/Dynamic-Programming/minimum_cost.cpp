//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

// program to calculate minimum cost in a 2D array when moving from (0,0)
// to destination such that we can only move down, right or bottom-right 

#include <iostream>
using namespace std;
 
int main() {
	int m, n;
	cout << "Please enter row and column size.\n"; 
	cin >> m >> n ;
	int a[m][n];
	cout << "Please enter elements.\n"; 
	for(int i = 0; i < m ;i++){
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	// storing sum across 1st row
	for(int i = 1; i < n; i++)
		a[0][i] += a[0][i - 1];
	// stoing sum across 1st column
	for(int i = 1; i < m; i++)
		a[i][0] += a[i - 1][0];
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			// taking minimum cost by taking min of left, top and top-left element
			a[i][j] += ( min(a[i - 1][j], min( a[i][j - 1], a[i - 1][j - 1] ) ) );
		}
	}
	// value at destination
	cout << "Minimum cost : " << a[m-1][n-1] << endl;
	return 0;
} 

// Time Complexity : O(mn)
// This is because we use nested loops of m and n to iterate over the original matrix
// to calculate minimum cost. 

// Auxililary Space Complexity : O(1)