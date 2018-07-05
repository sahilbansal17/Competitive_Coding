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
	#define MAX 100010

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, v;
	vi a;

	cin >> n;
	double total = 0;
	rep(i, n){
		cin >> v;
		a.pb(v);
		total += v;
	}	

	srt(a);

	double g = 1.0 * total / n;

	// cout << g;
	if(g >= 4.5){
		cout << "0";
	}
	else{
		int count = 0;
		rep(i, n){
			total += 5 - a[i];
			g = 1.0*total/n;
			count ++;
			if(g >= 4.5){
				break;
			}
		}
		cout << count;
	}

	return 0;
}