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



int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n;

	cin >> n;

	int cost[4] = {0, 0, 0, 0};

	rep(j, 4){
		string s;
		rep(i, n){
			cin >> s;
			int cc = 0; /* cc: current cost */
			/* match with 0101010101010...*/
			rep(k, n){
				if(k % 2 == 0 && s[k] == '1'){
					cc ++;
				}
				else if(k % 2 == 1 && s[k] == '0'){
					cc ++;
				}
			}
			/*  match with 
				01010101...
				10101010...
			*/
			if(i % 2 == 0){
				cost[j] += cc; 
			}
			else{
				cost[j] += n - cc;
			}
		}
	}

	sort(cost, cost + 4);
	/*
	rep(i, 4){
		cout << cost[i] << " ";
	}
	//*/

	cout << cost[0] + cost[1] + n*n - cost[2] + n*n - cost[3];
	return 0;
}