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

vi a(MAX);
vi t(MAX);
vi sumPre(MAX, 0); /* without considering power */
vi sumPost(MAX, 0); /* considering power */
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n, k;
	cin >> n >> k;

	rep(i, n){
		cin >> a[i];
	}
	rep(i, n){
		cin >> t[i];
	}
	if(t[0])
		sumPre[0] = a[0];
	sumPost[0] = a[0];	
	rep1(i, n){
		if(t[i] == 1){
			sumPre[i] = sumPre[i - 1] + a[i];
		}
		else{
			sumPre[i] = sumPre[i - 1];
		}
		sumPost[i] = sumPost[i - 1] + a[i];
	}

	int sum;
	int max = sumPost[k - 1] + sumPre[n - 1] - sumPre[k - 1];
	rep1(i, n - k + 1){
		/* using power at i-th minute */
		sum = sumPre[i - 1] + sumPost[k + i - 1] - sumPost[i - 1] + sumPre[n - 1] - sumPre[k + i - 1];
		if(sum > max){
			max = sum;
		}
		// cout << sum << " ";
	}
	cout << max;
	return 0;
}