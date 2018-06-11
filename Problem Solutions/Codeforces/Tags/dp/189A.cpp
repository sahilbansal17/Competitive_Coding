#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, a, b, c;

	cin >> n >> a >> b >> c;

	int dp[n + 1];
	// dp[i] represents the maximum pieces to get ribbon of length i

	fill(dp, dp + n + 1, -4000);
	dp[0] = 0;

	fl(i, a, n + 1){
		dp[i] = max(dp[i], dp[i - a] + 1);
	}
	fl(i, b, n + 1){
		dp[i] = max(dp[i], dp[i - b] + 1);
	}
	fl(i, c, n + 1){
		dp[i] = max(dp[i], dp[i - c] + 1);
	}

	cout << dp[n];
	return 0;
}