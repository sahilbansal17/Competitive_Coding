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
	#define rep1(i,n) fl(i,1,n)
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
	#define MAX 200010

vi a;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n, k, x;

	cin >> n >> k;

	rep(i, n){
		cin >> x;
		a.pb(x);
	}

	srt(a);

	int ct = 0, cct = 0;

	rep(i, n - 1){
		// cout << a[i] << " " << a[i + 1] << "\n";
		if(a[i] != a[i + 1] && a[i + 1] <= a[i] + k){
			if(cct > 0){
				ct += cct + 1;
				cct = 0;
			}
			else{
				ct ++;
			}
		}
		else if(a[i] == a[i + 1]){
			cct ++ ;
		}
		else{
			cct = 0;
		}
	}
	cout << n - ct;
	return 0;
}