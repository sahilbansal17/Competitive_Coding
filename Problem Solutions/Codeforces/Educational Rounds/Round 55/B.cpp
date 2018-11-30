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
    /* String methods */
    #define dig(i)          (s[i] - '0')
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
    #define IINF            0x3f3f3f3f
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt_r[MAX] = {0}, cnt_l[MAX] = {0}, tot_g = 0, res = 0;
    if (s[0] == 'G') {
        cnt_l[0] = 1;
        tot_g ++;
        res = 1;
    }
    if (s[n - 1] == 'G') {
        cnt_r[n - 1] = 1;
        res = 1;
    }

    rep1 (i, n) {
        if (s[i] == 'G') {
            tot_g ++;
            cnt_l[i] = cnt_l[i - 1] + 1;
        }
        else {
            cnt_l[i] = 0;
        }

        res = max(res, cnt_l[i]);
    }

    rfl (i, n - 2, 0) {
        if (s[i] == 'G') {
            cnt_r[i] = cnt_r[i + 1] + 1;
        }
        else {
            cnt_r[i] = 0;
        }
        res = max(res, cnt_r[i]);
    }

    // trace1(res);
    /*/
    rep (i, n) {
        cerr << cnt_r[i] << " ";
    }
    //*/

    int idx = -1;
    rep (i, n) {
        if (s[i] == 'S' && i > 0 && i < n - 1) {
            if (tot_g > cnt_l[i - 1] + cnt_r[i + 1]) {
                res = max (cnt_l[i - 1] + cnt_r[i + 1] + 1, res);
                idx = i;
            }
            else {
                res = max (cnt_l[i - 1] + cnt_r[i + 1], res);
            }
        }
        else if (s[i] == 'S' && i == 0 && tot_g > cnt_r[i + 1]) {
            res = max (res, cnt_r[i + 1] + 1);
            idx = i;
        }
        else if (s[i] == 'S' && i == n - 1 && tot_g > cnt_l[i - 1]) {
            res = max (res, cnt_l[i - 1] + 1);
            idx = i;
        }
        // trace2(idx, res);
    }

    cout << res << endl;

    return 0;
}