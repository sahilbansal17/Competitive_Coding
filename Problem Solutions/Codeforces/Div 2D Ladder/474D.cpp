/* 	Problem Link	: 	http://codeforces.com/problemset/problem/474/D
	Problem Name 	: 	Flowers
 	author 			: 	sahilbansal17
	date			:	23rd Jan, 2018	
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define MOD 1000000007


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,k,a,b,res;
	cin >> t >> k;

	ll dp[100005];
	dp[0] = 0; // no ways for eating 0 flowers
	fl(i,1,k+1){
		if(i < k){
			dp[i] = 1; // only one way, all red flowers
		}
		else if(i == k){
			dp[i] = 2; // 2 ways, either all red or all white
		}
	}
	fl(i,k+1,100001){
		dp[i] = (dp[i-1] + dp[i-k])%MOD; // recurrence relation
	}

	int solve[100005]; // storing the prefix sum
	solve[0] = 0;
	fl(i,1,100001){
		solve[i] = (dp[i] + solve[i-1])%MOD;
	}

	// rep(i,100005){
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n";

	while(t--){
		cin >> a >> b;
		res = solve[b] - solve[a-1];
		if(res < 0){
			res += MOD;
		}
		cout << res << "\n";
	}

	return 0;
}