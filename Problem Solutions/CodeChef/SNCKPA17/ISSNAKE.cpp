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
    const ll MAX = 505LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int n;
char g[2][MAX];

bool visited[2][MAX];

bool dfs (int i, int j) {
    // trace2(i, j);
    visited[i][j] = true;
    if (g[i ^ 1][j] == '#' && !visited[i ^ 1][j]) {
        return dfs (i ^ 1, j);
    }
    if (j + 1 < n && g[i][j + 1] == '#' && !visited[i][j + 1]) {
        return dfs (i, j + 1);
    }
    if (j - 1 >= 0 && g[i][j - 1] == '#' && !visited[i][j - 1]) {
        return dfs (i, j - 1);
    }
    return false;
}

void reset () {
    rep (i, 2) {
        rep (j, n) {
            visited[i][j] = false;
        }
    }
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;
    
    int t;
    cin >> t;

    while (t --) {
        cin >> n;

        rep (i, 2) {
            rep (j, n) {
                cin >> g[i][j];
                visited[i][j] = false;
            }
        }

        rep (j, n) {
            if (g[0][j] == '#') {
                dfs (0, j);
                break;
            }
        }

        bool res1 = true, res2 = true;

        rep (i, 2) {
            rep (j, n) {
                if (!visited[i][j] && g[i][j] == '#') {
                    res1 = false;
                    break;
                }
            }
        }

        reset();

        rep (j, n) {
            if (g[1][j] == '#') {
                dfs (1, j);
                break;
            }
        }
        
        rep (i, 2) {
            rep (j, n) {
                if (!visited[i][j] && g[i][j] == '#') {
                    res2 = false;
                    break;
                }
            }
        }
        
        if (res1 | res2) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}