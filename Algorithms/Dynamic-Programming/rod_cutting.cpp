// This program addresses the famous Rod Cutting Problem
// Problem Statement: Given a rod of length n and an array 
//                    of prices that contains prices of all pieces of size smaller 
//                    than n. Determine the maximum value obtainable by cutting up the 
//                    rod and selling the pieces.
// Input Format : The first line contains n, the length of the rod.
//                The next line contains n space separated integers, ith of them being equal
//                to cost of rod of length i.
// Output Format : The length(s) of the piece(s) leading to maximum cost followed by the maximum cost. 
// Approach Used : Dynamic programming
//
// The solution uses both bottom to top and top to bottom approach of dynamic programming. It is clear that the maximum price 
// of a piece of length i is the same as  maximum among total cost of (piece of length j + piece of length(i-j) )
// such that j<=i. Now the advantage of dynamic programming is that instead of using cost of piece of length(i-j)
// we use its pre-calculated value/stored value(here price array). Since we use a bottom to up approach it is ensured
// that this value is always computed before it is required. In a similar manner in top to bottom approach each value is looked up
// first in the price array.If not calculated previously it is calculated ans stored. Hence price[n] easily gives us the maximum 
// achievable price. Additionally we use an array length_now to keep track of the pieces used to reach the maximum cost in 
// a chain-like structure.

// Author : monsijb

#include<iostream>
#include<vector>
using namespace std;

// Auxiliary array in which price[i] stores the maximum price in which 
// the rod of length i can be sold. Clearly price[0]=0 
int price[10001];

// Array to keep track of the pieces used at each stage
int length_now[10001];

// Vector to store the initial input data
vector<int>arr;

// Function to initialize price and length_now array
void initialization(int n)
{
	price[0]=0;
	for(int i=1; i<=10000; i++)
	{
		length_now[i]=-1;
		price[i]=-1;
	}
}

// Solves via top to bottom recusion and memoization
int rcProblemR(int n)
{
	// terminating condition
	if(n<=0)
		return 0;
		
	// If already calculated, that value is returned
	else if(price[n]!=-1)
		return price[n];
	// If not calculated then it is calculated below
	int curr_max =INT_MIN;
	int curr_cost,curr_length;
	
	for(int i=0; i<n; i++)
	{
		curr_cost = arr[i] + rcProblemR(n-i-1);
		if(curr_cost > curr_max)
		{
			curr_max = curr_cost;
			curr_length = i;
		}
	}
	
	// Length of piece used to get piece of length i is also stored
	length_now[n]=curr_length+1;
	
	// Value stored and returned simultaneously
	return (price[n]=curr_max);
}

// Solves via bottom to top approach
void rcProblem(vector<int>arr)
{
	int n = arr.size();
	int current_length;

	for(int i=1; i<=n ;i++)
	{
		// Current maximum achievable price for rod of length i
		int current_max = INT_MIN;
		
		for(int j=0; j<i; j++)
		{
			int current_price = arr[j] + price[i-(j+1)];
			if(current_price > current_max)
			{
				current_max = current_price;
				current_length = j;
			}
		}
		
		// Value calculated is stored appropriately(maximum cost of piece having length i) 
		price[i] = current_max;
		
		// Length of piece used to get piece of length i is also stored
		length_now[i]=current_length+1;
	}

	cout << "Maximum achievable price: " << price[n] << "\n";
	
	// Starting from length n we move backwards to get what pieces are used to get the maximum cost 
	int position=n;
	cout << "Piece(s) of length : ";
	
	// Continously moving to next piece till the required length is reached.
	while((position - length_now[position])!=0)
	{
		cout << length_now[position] << " ";
		position = position - length_now[position];
	}
	cout << length_now[position] << "\n";
}

int main()
{
	int n,x;
	cout << "Enter the length of the rod: ";
	cin >> n;
	cout << "Enter the cost of pieces having length 1 to " << n << "(" << n <<  " integers):\n"; 
	for(int i=0; i<n; i++)
	{
		cin >> x;
		arr.push_back(x);
	}
	
	// Using bottom to top approach
	initialization(n);
	rcProblem(arr);
	
	
	// Using top to bottom approach
	initialization(n);
	cout << "\nMaximum achievable price: " << rcProblemR(n) << "\n";
	int position=n;
	cout << "Piece(s) of length : ";
	
	// Continously moving to next piece till the required length is reached.
	while((position - length_now[position])!=0)
	{
		cout << length_now[position] << " ";
		position = position - length_now[position];
	}
	cout << length_now[position] << "\n";
	return 0;
}


// Time complexity:O(n^2)(For both approaches)
// The two nested loops may run for altogether 1+2+3+...n=(n(n+1))/2. So clearly the time complexity is O(n^2).
// Additionally as the complexity is O(n^2) , it will run under 1s time limit for n approximately 1<=n<=10000. Hence the size of
// price and length_now array is taken accordingly.
//
// Space complexity:O(n)(For both approaches)
// All auxiliary memory locations(price,length_now) have size of n+1. So the space complexity is of O(n).
