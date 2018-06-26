// This program solves the problem of Longest Increasing Subsequence(LIS)
// Problem Statement: The Longest Increasing Subsequence (LIS) problem is to find the length of the longest 
//                    subsequence of a given sequence such that all elements of the subsequence are sorted 
//                    in increasing order.
// Input Format : The first line contains n,the number of elements of the array.
//                The second line contains n space separated integers.
// Output Format : A single number specifying the length of LIS, followed by each element of LIS.

// Approach Used : Dynamic Programming

// Intuition behind dynamic programming:
// In this solution each element of the aux vector ,say at index i stores the LIS possible with the 
// last element arr[i](ith element of the input array). So clearly, the first element of aux stores just arr[0].
// Next for finding LIS for other elements as last element of that sequence, an iteration is made for
// all the previous LIS whose last element is less than the current element. If such a sequence is found
// the largest of these is taken with the last element appended at the end of it. Finally the sixe of the maximum sequence
// along with the sequence is printed. The memorisation of previous LIS is a key to dynamic programming here and forms the
// overlapping subproblems.
 
#include<iostream>
#include<vector>
using namespace std;


void calLIS(vector<int>arr)
{
	vector< vector<int> > aux(arr.size());
	int final_ans=INT_MIN;
	int position;
	aux[0].push_back(arr[0]);
	
	for(int i=1; i<arr.size(); i++)
	{
		// Iterating over all previous LIS
		for(int j=0; j<i; j++)
		{
			
			if( (arr[j] < arr[i]) && ( aux[i].size() < (aux[j].size())) )
			{
				aux[i]=aux[j];
			}
		}
		// Appending current element at the end of it.
		aux[i].push_back(arr[i]);
		if(int(aux[i].size()) > final_ans)
		{
			final_ans = int(aux[i].size());
			position = i;
		}
	}
	
	cout << "Maximum size :" << final_ans << "\n";
	cout << "Subsequence is: ";
	for(int j=0; j<final_ans; j++)
		cout << aux[position][j] << " ";
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

// Space complexity analysis: O(n^2)
// Due to the use of vector aux of size n*n, the space complexity is O(n^2).
