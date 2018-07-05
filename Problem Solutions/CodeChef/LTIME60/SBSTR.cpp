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

	int t;
	cin >> t;

	string s; 
	int k;

	while(t --){
		cin >> s >> k;

		int n = slen(s);
		int ans = 0;
		rep(i, n){
			int max_occ = 0, count_distinct = 0;
			vi occ(26, 0);
			rfl(j, i, 0){
				if(occ[s[j] - 'a'] == 0){
					count_distinct ++;
				}
				max_occ = max(max_occ, ++occ[s[j] - 'a']);
				if(count_distinct >= k && (max_occ*count_distinct == i - j + 1)){
					ans ++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}