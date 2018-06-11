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

	int n, val;
	vi a;

	cin >> n;

	rep(i, n){
		cin >> val;
		a.pb(val);
	}

	vi dp(n + 1, 1); // dp array, dp[i] representing the max length subsequence ending at index i
	vi prev(n + 1, 0); // stores the previous at that location
	rep(i, n){
		prev[i] = i;
	}
	rep(i, n){
		int max = dp[i], max_ele_index = i;
		fl(j, 0, i){
			if(a[j] == a[i] - 1 && (dp[j] + 1) > max){
				max = dp[j] + 1;
				max_ele_index = j;
			}
		}
		dp[i] = max;
		prev[i] = max_ele_index;
	}

	int max_length = 0, max_index = 0;
	rep(j, n){
		// cout << dp[j] << " " << prev[j] << "\n";
		if(dp[j] > max_length){
			max_length = dp[j];
			max_index = j;
		}
	}

	// cout << dp[n-1];

	int cur = max_index;
	vi revList;
	revList.pb(cur);

	while(prev[cur] != cur){
		cur = prev[cur];
		revList.pb(cur);
	}

	cout << max_length << "\n"; 
	rfl(i, revList.size()-1, 0){
		cout << revList[i] + 1 << " ";
	}
	return 0;
}