#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
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
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
typedef complex <double>    pnt;
typedef vector <pnt>        vpnt;
typedef priority_queue <pii, vpii, greater<pii> > spq;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i < (b); i ++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    #define mt              make_tuple
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define endl            '\n'
    /* Mathematical */
    #define oo              0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 200010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;
    
    int t;
    cin >> t;

    string s;

    rep (i, t) {
        cin >> s;
        int low = 0, up = 0, no = 0;
        int n = slen(s);
        int ui = -1, li = -1, ni = -1;
        rep (j, n) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                up ++;
                ui = j;
            }
            else if (s[j] >= 'a' && s[j] <= 'z') {
                low ++;
                li = j;
            }
            else if (s[j] >= '0' && s[j] <= '9') {
                no ++;
                ni = j;
            }
        }
        
        if (up == 0 && low == 0) {
            s[0] = 'A';
            s[1] = 'b';
        }
        else if (low == 0 && no == 0) {
            s[0] = 'a';
            s[1] = '1';
        }
        else if (up == 0 && no == 0) {
            s[0] = 'A';
            s[1] = '1';
        }
        else if (up == 0) {
            if (low >= 2) {
                rep (j, n) {
                    if (s[j] >= 'a' && s[j] <= 'z') {
                        s[j] = 'A';
                        break;
                    }
                }
            }
            else if (no >= 2) {
                rep (j, n) {
                    if (s[j] >= '0' && s[j] <= '9') {
                        s[j] = 'A';
                        break;
                    }
                }
            }
        }
        else if (low == 0) {
            if (up >= 2) {
                rep (j, n) {
                    if (s[j] >= 'A' && s[j] <= 'Z') {
                        s[j] = 'a';
                        break;
                    }
                }
            }
            else if (no >= 2) {
                rep (j, n) {
                    if (s[j] >= '0' && s[j] <= '9') {
                        s[j] = 'a';
                        break;
                    }
                }
            }
        }
        else if (no == 0) {
            if (low >= 2) {
                rep (j, n) {
                    if (s[j] >= 'a' && s[j] <= 'z') {
                        s[j] = '1';
                        break;
                    }
                }
            }
            else if (up >= 2) {
                rep (j, n) {
                    if (s[j] >= 'A' && s[j] <= 'Z') {
                        s[j] = '1';
                        break;
                    }
                }
            }
        }
        cout << s << endl;
    }    

    return 0;
}