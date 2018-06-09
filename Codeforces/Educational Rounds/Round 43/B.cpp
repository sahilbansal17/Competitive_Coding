/* My Bad fortune! In the last 4 submissions of this problem,
 * I somehow got ONLINE_JUDGE replaced with ONLINE_JUDG
 * That's why there was no output coming. */

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
	#define MAX 10010
	
/* Global variable declarations */


int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	ull n, k, m;
	cin >> n >> m >> k;	

	if(k < n){
		cout << k + 1 << " " << 1 << "\n";
		return 0;
	}
	ull rem = (k - n) % (m - 1);
	ull check = (k - n)/(m - 1);
	ull x = n - check;
	cout << x << " ";
	if(x % 2 == 1){
		cout << m - rem << "\n";
	}
	else{
		cout << rem + 2 << "\n";
	}
	return 0;
}