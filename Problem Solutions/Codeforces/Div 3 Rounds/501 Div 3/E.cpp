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
    #define INF             0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 10010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

vector < pair < int, pii > > res; // sz, x, y
char s[1005][1005];
bool done[1005][1005];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;

    rep(i, n){
        rep(j, m){
            cin >> s[i][j];
        }
    }
    
    pii left, right, top, bottom;

    int x, y, siz;

    rep1(i, n - 1){
        rep1(j, m - 1){

            if(s[i][j] == '*'){
                x = i;
                y = j;
                siz = 0;

                // unchanged
                left.F = x;
                right.F = x;
                top.S = y;
                bottom.S = y;
                // changeable
                left.S = y;
                right.S = y;
                top.F = x;
                bottom.F = x;

                fl(k, 1, 1000){
                    left.S --;
                    right.S ++;
                    top.F --;
                    bottom.F ++;
                    if(left.S < 0 || right.S >=m || top.F < 0 || bottom.F >= n){
                        break;
                    }
                    if(s[x][left.S] == '*' && s[x][right.S] == '*' && s[top.F][y] == '*' && s[bottom.F][y] == '*'){
                        done[x][left.S] = true;
                        done[x][right.S] = true;
                        done[top.F][y] = true;
                        done[bottom.F][y] = true;
                        siz = k;
                    }
                    else{
                        break;
                    }
                }
                if(siz > 0){
                    done[x][y] = true;
                    res.pb(mp(siz, mp(x + 1, y + 1)));
                }
            }
        }
    }

    rep(i, n){
        rep(j, m){
            if(s[i][j] == '*' && !done[i][j]){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << res.size() << endl;

    rep(i, res.size()){
        cout << res[i].S.F << " " << res[i].S.S << " " << res[i].F << "\n";
    }

    return 0;
}