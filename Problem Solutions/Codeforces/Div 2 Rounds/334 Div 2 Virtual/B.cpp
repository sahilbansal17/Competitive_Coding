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

	vi s(MAX, 0);

	rep(i, n){
		cin >> s[i];
	}

	int smallest_s = -1;

	if(n == 2*k){
		int current_max = 0;
		for(int i = 0, j = n - 1; i < j; i ++, j --){
			current_max = s[i] + s[j];
			if(current_max > smallest_s){
				smallest_s = current_max;
			}
		}
		cout << smallest_s;
		return 0;
	}
	else if(n < 2*k){
		int current_max = 0;
		int last = n - 1;
		while(last >= 0 && n < 2*k){
			current_max = s[last];
			last --;
			if(current_max > smallest_s){
				smallest_s = current_max;
			}
			n -= 1;
			k -= 1;
		}
		// cout << last << "\n";
		for(int i = 0, j = last; i < j; i ++, j --){
			current_max = s[i] + s[j];
			if(current_max > smallest_s){
				smallest_s = current_max;
			}
		}
		cout << smallest_s;
		return 0;
	}
	else if(n )
	return 0;
}