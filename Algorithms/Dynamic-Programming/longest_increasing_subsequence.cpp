// This program solves the problem of Longest Increasing Subsequence(LIS)
// Problem Statement: The Longest Increasing Subsequence (LIS) problem is to find the length of the longest 
//                    subsequence of a given sequence such that all elements of the subsequence are sorted 
//                    in increasing order.
// Input Format : The first line contains n,the number of elements of the array.
//                The second line contains n space separated integers.
// Output Format : A single number specifying the length of LIS followed by the sequence.

// Approach Used : Dynamic Programming

// Intuition behind dynamic programming:
// In this solution each element of the aux vector ,say at index i stores the length of LIS possible with the 
// last element arr[i](ith element of the input array). So clearly, the first element of aux stores just 1(only arr[0]).
// Next for finding LIS for other elements as last element of that sequence, an iteration is made for
// all the previous LIS whose last element is less than the current element. If such a sequence is found
// the largest of these is taken with the last element appended at the end of it(one is added actually to realise it). 
// Additionally the location of the last element is simultaneously stored in lis_parent array.Finally the 
// size of the maximum sequence is printed along with the sequence. The memoization of previous LIS length is a key to dynamic 
// programming here and is the technique to store the solutions of subproblems.
 
#include<iostream>
#include<vector>
using namespace std;


void calLIS(vector<int>arr)
{
	int n = arr.size();
	int aux[n];
	int ending_index=0;
	int lis_parent[n];
	vector<int>result_sequence;
	// By default the sequence ending with first element can only be of length 1
	aux[0]=1;
	
	// Initialising lis_parent with the own index as initially all have a size of 1
	for(int i=0; i<n; i++)
		lis_parent[i]=i;

	int final_ans = aux[0];
	for(int i=1; i<n; i++)
	{
		int curr_max=0;
		
		for(int j=0; j<i; j++)
		{
			// if last element is greater as well as its length is greater than the seen maximum
			if(arr[j] < arr[i] && aux[j]> curr_max)
			{
				curr_max = aux[j];
				lis_parent[i]=j;
			}
		}
		
		// 1 added to account the addition of the current element in the LIS.
		aux[i] = curr_max + 1;
		
		// Simple comparison to store the maximum among all LIS length.
		if(aux[i]>final_ans)
		{
			final_ans = aux[i];
			ending_index=i;
		}
	}
	
	cout << "Size of longest increasing subsequence: " << final_ans << "\n";
	
	// Continuously moving to the previous element and adding to the vector result_sequence
	result_sequence.push_back(arr[ending_index]);
	while(lis_parent[ending_index]!=ending_index)
	{
		ending_index = lis_parent[ending_index];
		result_sequence.push_back(arr[ending_index]);
	}
	
	cout << "Sequence is: ";
	for(int i=final_ans-1; i>=0; i--)
		cout << result_sequence[i] << " ";
	cout << "\n";
}

int main()
{
	int n,x;
	cout << "Enter the number of elements: ";
	cin >> n;
	vector<int>arr;
	cout << "Enter the elements of the array:\n";
	for(int i=0; i<n; i++)
	{
		cin >> x;
		arr.push_back(x);
	}
	calLIS(arr);
	return 0;
}

// Time complexity analysis: O(n^2)
// As this approach may lead to a maximum of n-1 iterations for the nth element, the time complexity is of the order O(n^2).

// Space complexity analysis: O(n)
// Due to the use of linear aux array of size n, the space complexity is O(n).
