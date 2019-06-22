#include <bits/stdc++.h>
using namespace std;

int cost(int start, int end, vector <int> &h) {
	return abs(h[start] - h[end]);
}

int minCost(int n, vector <int> &h, vector <int> &dp) {

	// base case
	if (n == 0) {
		return dp[0] = 0;
	}
	// memoized value
	if (dp[n] != INT_MAX) {
		return dp[n];
	}
	// recurrence relation
	dp[n] = INT_MAX;
	for (int backStep = 1; backStep <= 2; backStep ++) {
		if (n - backStep >= 0) {
			dp[n] = min(dp[n], minCost(n - backStep, h, dp) + cost(n - backStep, n, h));
		}
	}
	return dp[n];
}

int main () {

	int n, height;
	cin >> n;

	vector <int> h, dp;
	for (int i = 0; i < n; i ++) {
		cin >> height;
		h.push_back(height);
	}

	dp.resize(n, INT_MAX);
	cout << minCost(n - 1, h, dp);
}