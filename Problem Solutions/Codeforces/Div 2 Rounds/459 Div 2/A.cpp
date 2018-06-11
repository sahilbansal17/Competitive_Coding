/* 	author		: 	sahilbansal17
	date		:	29th Jan, 2018	
*/
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

int dp[1000] = {0};

int solve(int n){
	if(dp[n] != 0){
		return dp[n];
	}
	return dp[n] = solve(n-1) + solve(n-2);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1; 

	vi ht(1001,0);

	solve(1000);
	fl(i,1,1001){
		if(dp[i] > 1000){
			break;
		}
		ht[dp[i]] = 1;
	}

	fl(i,1,n+1){
		if(ht[i] == 1){
			cout << "O";
		}
		else
			cout << "o";
	}

	return 0;
}