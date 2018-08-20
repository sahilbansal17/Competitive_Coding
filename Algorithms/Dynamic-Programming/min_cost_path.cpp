//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find the minimum cost path
//th problem statement is as follows:-
//Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
//From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
//Cost of a path is defined as the sum of values of each cell through which path passes.

#include<iostream>
#include<climits>

using namespace std;

//Brute Force approach -Time Complexity(exponential)
//this is a helper function with additional paramaeters i and j
//here i and j denotes the starting or current location
//and m and n as the number of rows and columns 
int minCostPath(int **input,int m,int n,int i,int j){
	//base case of recursion when i and j are at final location return its value
	if(i==m-1 && j==n-1){
		return input[i][j];
	}
	
	//when i and j becomes equal to outside of matrix
	//than return infinity
	if(i>=m || j>=n){
		return INT_MAX;
	}
	
	//calling recursion on 3 paths because 3 paths are possible to go
	int x = minCostPath(input,m,n,i,j+1);
	int y = minCostPath(input,m,n,i+1,j+1);
	int z = minCostPath(input,m,n,i+1,j);
	
	//answer is the minimum of all the valuse got from recursive calls
	int ans = min(x,min(y,z)) + input[i][j];
	
	return ans;
}

int minCostPath(int **input,int m,int n){
	return minCostPath(input,m,n,0,0);
}

//Memoization Approach - Time Complexity(O(m*n))
//this is a helper function with additional array parameter which stores the results of recursive calls
int minCostPathMemoization(int **input,int m,int n,int i,int j,int **arr){
	//base case of recursion when i and j are at final location return its value
	if(i==m-1 && j==n-1){
		return input[i][j];
	}
	//when i and j becomes equal to outside of matrix
	//than return infinity
	if(i>=m || j>=n){
		return INT_MAX;
	}
	
	//if the value is already computed than no need to do anything just return it
	if(arr[i][j]!=-1){
		return arr[i][j];
	}
	
	//calling recursion and after that checking if the value got from recursion call
	//is not equal to infinity if not than storing them in the array for further use
	int x = minCostPathMemoization(input,m,n,i,j+1,arr);
	if(x<INT_MAX){
		arr[i][j+1] = x;
	}
	int y = minCostPathMemoization(input,m,n,i+1,j+1,arr);
	if(y<INT_MAX){
		arr[i+1][j+1] = y;
	}
	int z = minCostPathMemoization(input,m,n,i+1,j,arr);
	if(z<INT_MAX){
		arr[i+1][j] = z;
	}
	
	//answer is the inimum of all x ,y and z + input[i][j]
	int ans = min(x,min(y,z)) + input[i][j];
	arr[i][j] = ans;
	return ans;
}
//minCostPathMemoization() function uses memoization technique
int minCostPathMemoization(int **input,int m,int n){
	//creating a 2d array dynamically
	//and initializing it with -1
	int ** arr = new int*[m];
	for(int i=0;i<m;i++){
		arr[i] = new int[n];
		for(int j=0;j<n;j++){
			arr[i][j] = -1;
		}
	}
	//calling helper function with this array as additional parmaneter
	return minCostPathMemoization(input,m,n,0,0,arr);
}

//Dynamic Programming Approach - Time Complexity(O(m*n))
int minCostPathDP(int **input,int m,int n){
	//creating a 2d array dynamically
	int ** ans = new int*[m];
	for(int i=0;i<m;i++){
		ans[i] = new int[n];
	}
	
	//putting the value in the ans array fro input array as the last m,n element remains the same and has nod ement-dancy
	ans[m-1][n-1] = input[m-1][n-1];
	
	//last row - filling the last row as sum of current value and itts next
	for(int j=n-2;j>=0;j--){
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}
	
	//last col - filling the last col as sum of current value and itts next
	for(int i=m-2;i>=0;i--){
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}
	
	//now after puting the values in last row and col 
	//putting the value in the middle matrix 
	//iterating over them
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			//value at i,j is the addition of the its value an the minimum  of its neighbour
			ans[i][j] = input[i][j] + min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));
		}
	}
	
	//returning the minimum cost path
	return ans[0][0];
}

int main()
{
	int m,n;
	cout<<"Enter numbe of rows and columsn of matrix respectively : ";
	cin>>m >> n;
	int ** input = new int*[m];
	
	for(int i=0;i<m;i++){
		input[i] = new int[n];
		for(int j=0;j<n;j++){
			cin>>input[i][j];
		}
	}
	
	cout<<"Sum of Min cost path is Using Brute Force : "<<minCostPath(input,m,n)<<endl;
	cout<<"Sum of Min cost path is Using Memoization : "<<minCostPathMemoization(input,m,n)<<endl;
	cout<<"Sum of Min cost path is Using DP : "<<minCostPathDP(input,m,n)<<endl;
}
