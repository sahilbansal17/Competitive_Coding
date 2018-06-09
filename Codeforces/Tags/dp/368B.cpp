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

/* Global variable declaration space */

int a[MAX];
/* visited[i] denotes whether i is already seen or not */
bool visited[MAX];
/* dp[i] represents the no. distinct elements from a[i - 1] to a[n] */
int dp[MAX];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, m, count = 0, x;
	/* count denotes the no of distinct elements seen */
	cin >> n >> m;

	rep(i, n){
		cin >> a[i];
	}

	/* start from the last element, 
	 * if the element is seen then increase the count
	 * set dp[i + 1] = count */ 
	rfl(i, n - 1, 0){
		if(!visited[a[i]]){
			visited[a[i]] = true;
			count ++;
		}
		dp[i + 1] = count;
	}
	/*
	rep(i, n){
		cout << dp[i] << " ";
	}
	cout << "\n";
	//*/
	rep(i, m){
		cin >> x;
		cout << dp[x] << "\n";
	}
	return 0;
}