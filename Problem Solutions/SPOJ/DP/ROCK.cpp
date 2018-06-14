#include <bits/stdc++.h>
using namespace std;

int dp[205][205]; // dp[i][j] denotes the maximum length possible for a[i] to a[j] (i <= j)

int solve(int i, int j, string s){
	if(i == j){
		// base case: one length string
		if(s[i] == '1'){
			return dp[i][j] = 1;
		}
		return dp[i][j] = 0;
	}
	// memoization part
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	// if in string from i-th index to j-th index, count of 1's is more, 
	// then the entire length from i to j is the answer
	int count1 = 0, count0 = 0;
	for(int k = i; k <= j; k++){
		if(s[k] == '0'){
			count0 ++;
		}
		else{
			count1 ++;
		}
	}
	if(count1 > count0){
		return dp[i][j] = j - i + 1; // entire length
	}

	dp[i][j] = 0;
	// try all possible partitions, select one that yields maximum dp[i][j]
	for(int k = i; k < j; k++){
		if(solve(i, k, s) + solve(k + 1, j, s) > dp[i][j]){
			dp[i][j] = solve(i, k, s) + solve(k + 1, j, s);
		}
	}
	return dp[i][j];
}

int main(){

	string s;
	int t, n;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		cin >> s;

		// intialize dp table
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				dp[j][k] = -1;
			}
		}
		cout << solve(0, n - 1, s) << "\n";
	}

	/*/
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	//*/
	return 0;
}