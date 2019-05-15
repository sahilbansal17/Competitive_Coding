// gives WA, fixes required

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200010;
const ll MOD = 1000000007;

int dp[MAX][2];

int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int n;
	cin >> n;

	vector <int> A(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
	}

	memset(dp, 0, sizeof(dp));

	ll total_good = 0; // total number of good sub-sequences till now
	ll total_bad = 0; // total number of bad sub-sequences till now
	ll turned_good; // no. of subsequences which turned good in current iteration
	ll current_bad = 0;

	for (int i = 0; i < n; i ++) {
		turned_good = (dp[A[i]][0] + dp[A[i] - 1][0] + dp[A[i] + 1][0]);
		
		dp[A[i]][1] += (total_good + turned_good);
		dp[A[i]][1] %= MOD;

		current_bad = (total_bad - turned_good + 1 + 3*MOD) % MOD;

		dp[A[i]][0] += current_bad;
		dp[A[i]][0] %= MOD;

		total_bad += current_bad;
		total_bad %= MOD;

		total_good += total_good + turned_good;
		total_good %= MOD;

		cerr << endl;
	}

	cout << total_good << endl;
	return 0;
}