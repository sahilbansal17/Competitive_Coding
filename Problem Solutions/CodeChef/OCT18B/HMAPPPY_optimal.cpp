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
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

ll n, m;
vll a(MAX), b(MAX);

ll required_balloons (ll cost) {

    ll cur_balloons, total = 0;
    
    ll diff;
    rep (i, n) {
        diff = a[i]*b[i] - cost;

        if (diff <= 0) {
            continue;
        }
        // double x = 1.0*b[i] - 1.0*cost/b[i];
        // double diff = 1.0*a[i]*x;
        // trace1(diff);
        cur_balloons = ceil(1.0*diff/b[i]);

        if (a[i] * b[i] - cur_balloons * b[i] > cost) {
            cur_balloons += 1;
        }
        // if (diff > 0 && cur_balloons == 0) {
        //     cur_balloons = 1;
        // } 

        if (cur_balloons > 0)
            total += cur_balloons;
    }

    return total;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;

    cin >> n >> m;

    rep (i, n) {
        cin >> a[i];
    }

    ll max_cost = 0;

    rep (i, n) {
        cin >> b[i];
        if (a[i] * b[i] > max_cost) {
            max_cost = a[i] * b[i];
        }
    }

    // trace1(max_cost);    
    ll min_ans_possible = 1e18, max_ans_possible = 0, mid, ans = min_ans_possible;

    // int iter = 0;
    while (min_ans_possible >= max_ans_possible) {
        mid = (min_ans_possible + max_ans_possible)/2;
        if (required_balloons(mid) <= m) {
            min_ans_possible = mid - 1;
            if (mid < ans) {
                ans = mid;
            }
        }
        else {
            max_ans_possible = mid + 1;
        }
        // trace2(mid, required_balloons(mid));
        // trace2(min_ans_possible, max_ans_possible);
        // iter ++;
        // if (iter == 100) {
        //     break;
        // }
    }
    cout << ans << endl;

    return 0;
}