#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i<(b); i++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a);i>=(b);i--)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(),(v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define MOD             1000000007
    #define MAX             100010
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          ((x).begin(), (x).end())
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, val;
	vi a;

	cin >> n;

	rep(i, n){
		cin >> val;
		a.pb(val);
	}

	map <int, int> dp;
	
	int ans = 0, lst = 0; // lst is the last element of the req subsequence

	rep(i, n){
		int ele = a[i];
		// largest length of subsequence ending at ele is = 1 + length of that ending at ele - 1
		dp[ele] = dp[ele - 1] + 1;
		if(ans < dp[ele]){
			ans = dp[ele];
			lst = ele;
		}	
	}

	vi res; 

	// find indices of the required subsequence
	rfl(i, n - 1, 0){
		if(a[i] == lst){
			res.pb(i);
			lst --;
		}
	}

	reverse(res.begin(), res.end());
	
	cout << ans << "\n";
	rep(i, ans){
		cout << 1 + res[i] << " ";
	}


	return 0;
}