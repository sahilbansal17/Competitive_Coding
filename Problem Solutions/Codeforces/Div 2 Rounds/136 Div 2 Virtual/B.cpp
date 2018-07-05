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
    
vi digits(10, 0);
bool check_digits(int n){
    while(n){
        int dig = n % 10;
        n /= 10;
        if(digits[dig] > 0){
            re true;
        }
    }
    re false;
} 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int x;

    cin >> x;

    int cp = x;
    while(cp){
        int dig = cp % 10;
        cp /= 10;
        digits[dig] ++;
    }

    int fac = 1;
    int max_poss = sqrt(x);
    int ans = 0;
    while(fac <= max_poss){
        if(x % fac == 0){
            if(check_digits(fac)){
                ans ++;
            }
            if(check_digits(x/fac) && fac != x/fac){
                ans ++;
            }
        }
        fac ++;
    }

    cout << ans;

    return 0;
}