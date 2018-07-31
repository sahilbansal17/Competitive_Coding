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
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }

	
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

    int n, k;

    cin >> n >> k;

    vi a(n + 1, 0), sum(n + 1, 0);

    rep1(i, n + 1){
        cin >> a[i];
        if(i == 1){
            sum[1] = a[1];
        }
        else{
            sum[i] = sum[i - 1] + a[i];
        }
    }

    double check_sum, max_temp = 0.00, temp;
    fl(i, k, n + 1){
        fl(j, i, n + 1){
            check_sum = sum[j] - sum[j - i];
            temp = check_sum/i;
            // cout << temp << "\n";
            if(temp >= max_temp){
                max_temp = temp;
            }
        }
    }
    cout << fixed;
    cout << setprecision(15) << max_temp;
	return 0;
}