#include <bits/stdc++.h>
using namespace std;

class BadNeighbors{

public:

	/*

	Given a vector, the items are number listed in a clockwise order,
	where 1st and last elements are also connected.
	We need to find maximum sum of set of numbers, such that no two numbers
	appear consecutively in the vector.

	*/
	// solve for subprolem [i, j) not considering the circularity 
	// i.e. a[i] and a[j - 1] can be chosen
	int solve(int i, int j, vector <int> &a){
		int n = a.size();
		int dp[n]; // dp[i] represents the maximum sum possible if i-th index element is chosen 
		// [for subproblem size upto i elements only, i.e. elements after i-th index not considered]
		
		dp[i] = a[i]; // trivial case

		// fill the dp table for all elements indexed from i+1 to j-1
		for(int k = i + 1; k < j; k ++){
			dp[k] = a[k]; // current best possible sum

			// index l = k-1 can't be chosen as we chose a[k] in dp[k]
			// if best sum upto l-th index + a[k] > best sum upto k-th index
			// then update best sum upto k-th index
			for(int l = i; l < k - 1; l ++){
				if(dp[l] + a[k] > dp[k]){
					dp[k] = dp[l] + a[k];
				}
			}	
		}
		// find the maximum of best sums possible for all the indexes
		int res = 0;
		for(int k = i; k < j; k ++){
			res = max(res, dp[k]);
		} 
		return res;
	}

	int maxDonations(vector <int> donations){
		int n = donations.size();

		// solve two subproblems and find the maximum of them
		// case 1: consider that first element is excluded, so last element may or may not be chosen
		int res1 = solve(1, n, donations);
		// case 2: consider that last element is excluded, so that first element may or may not be chosen
		int res2 = solve(0, n - 1, donations);

		return max(res1, res2);
	}
};

int main(){

	int arr[] = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
	vector <int> test(arr, arr + sizeof(arr)/sizeof(arr[0]));

	BadNeighbors b;
	cout << "\n" << b.maxDonations(test) << "\n";

	return 0;
}