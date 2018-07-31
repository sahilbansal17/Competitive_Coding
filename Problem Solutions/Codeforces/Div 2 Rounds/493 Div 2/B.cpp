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

    int n, x, b;

    cin >> n >> b;

    vi a;

    vi odd(n, 0);
    vi even(n, 0);
    rep(i, n){
        cin >> x;
        a.pb(x);
        if(i == 0){
            if(x & 1){
                odd[i] = 1;
            }
            else{
                even[i] = 1;
            }
        }
        else{
            if(x & 1){
                odd[i] = odd[i - 1] + 1;
                even[i] = even[i - 1];
            }
            else{
                odd[i] = odd[i - 1];
                even[i] = even[i - 1] + 1;
            }
        }
    }           

    vi costs;

    if(n % 2 != 0){
        cout << "0";
    } 
    else{
        /*/
        cout << "odd\n";
        rep(i, n){
            cout << odd[i] << " ";
        }
        cout << "\neven\n";
        rep(i, n){
            cout << even[i] << " ";
        }
        //*/
        // cout << "\n";
        for(int i = 1; i < n - 2; i += 2){
            int cost = abs(a[i + 1] - a[i]);
            if(odd[i] == even[i]){
                costs.pb(cost);
            }
        }
        srt(costs);
        int cc = 0, cuts = 0;
        rep(i, costs.size()){
            if(cc + costs[i] > b){
                break;
            }
            cc += costs[i];
            cuts ++;
        }
        cout << cuts;
    }

    return 0;
}