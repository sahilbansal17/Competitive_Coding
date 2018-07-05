#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 100010


	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, k;
	cin >> n >> k;

	int p[MAX];
	int c[MAX];

	rep(i, n){
		cin >> p[i];
	}
	rep(i, n){
		cin >> c[i];
	}

	vector < pair <int, pair <int, int> > > vp;

	rep(i, n){
		vp.pb(mp(p[i], mp(i, c[i])));
	}

	// power
	srt(vp);
	
	/*/
	cout << "VP:\n";
	rep(i, n){
		cout << vp[i].F << " " << vp[i].S.F << " " << vp[i].S.S << "\n";
	}
	cout << "DP:\n";
	//*/

	int dp[11];
	rep(i, 11){
		dp[i] = -1;
	}

	ll sum[MAX], sum2[MAX];

	sum[0] = vp[0].S.S;

	fl(i, 1, n){
		sum[i] = vp[i].S.S;
		rep(j, 10){
			if(vp[i - 1].S.S > dp[j]){
				rfl(l, k - 1, j){
					dp[l + 1] = dp[l];
				}
				dp[j] = vp[i - 1].S.S;
				break;
			}
		}
		/*/
			rep(l, 10){
				cout << dp[l] << " ";
			}
			cout << "\n\n";
		//*/
		fl(l, 0, k){
			if(dp[l] != -1)
			sum[i] += dp[l];
		}
	}

	rep(i, n){
		int ind = vp[i].S.F;
		sum2[ind] = sum[i];
	}
	rep(i, n){
		cout << sum2[i] << " ";
	}
	return 0;
}