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

    int a, b, x;

    cin >> a >> b >> x;

    if(a > b){
        while(x > 1){
            cout << "01";
            x -= 2;
            a --;
            b --;
        }
        if(x == 0){
            rep(i, b){
                cout << "1";
            }
            rep(i, a){
                cout << "0";
            }
        }
        if(x == 1){
            rep(i, a){
                cout << "0";
            }
            rep(i, b){
                cout << "1";
            }
        }
    }
    else{
        while(x > 1){
            cout << "10";
            x -= 2;
            a --;
            b --;
        }
        if(x == 0){
            rep(i, a){
                cout << "0";
            }
            rep(i, b){
                cout << "1";
            }
        }
        if(x == 1){
            rep(i, b){
                cout << "1";
            }
            rep(i, a){
                cout << "0";
            }
        }
    }

	return 0;
}