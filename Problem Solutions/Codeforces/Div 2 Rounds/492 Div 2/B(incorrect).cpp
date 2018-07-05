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

	int n;

	cin >> n;

	vpii e;

	int num;
	rep(i, n){
		cin >> num;
		e.pb(mp(num, i)); 
	}		

	srt(e);

	int result = -1, current_pos = 0;
	int min_pos = n, min_after_current = -1;

	rep(i, n){
		int p = e[i].F;
		int j = e[i].S;
		// cout << "p: " << p << ", j: " << j << "\n";
		current_pos = p % n;
		// cout << "current_pos: " << current_pos << "\n";
		// cout << "Min: " << min_pos << "\n";
		// cout << "Max: " << min_after_current << "\n";
		// cout << "\n";

		if(j == current_pos){
			// cout << "Done:";
			result = j;
			break;
		}
		if(min_pos <= current_pos && current_pos <= min_after_current){
			result = min_after_current;
			break;
		}
		int k = i ;
		while(e[k].F == p){
			if(e[k].S < min_pos){
				min_pos = e[k].S;
			}
			if(min_after_current == -1 && e[k].S > current_pos){
				min_after_current = e[k].S;
			}
			if(e[k].S < min_after_current && e[k].S > current_pos){
				min_after_current = e[k].S;
			}
			k ++;
		}
	}

	cout << 1 + result;
	return 0;
}