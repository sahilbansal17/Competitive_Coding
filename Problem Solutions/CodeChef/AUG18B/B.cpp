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
/* Constants */
    const ll MOD = 100000000LL;
    const ll MAX = 1e10;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

#define isOn(S, j) (S & (1 << j))

vll num_with_two_set_bits;

// store numbers with two set bits
void initialize(){
    int high = 1;
    ll current = 0;
    
    while (high < 32) {
        int low = 0;
        while (low < high) {
            current = (1ll << low) + (1ll << high);
            
            num_with_two_set_bits.pb(current);

            low ++;
        }
        high ++;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int t, n;
    cin >> t;

    initialize();

    // trace1("\n");
    // trace1(sz(num_with_two_set_bits));
    // trace1(num_with_two_set_bits[sz(num_with_two_set_bits) - 1]);

    int total = sz(num_with_two_set_bits);

    while (t --) {
        cin >> n;
        /*
        int cnt = 0, first, second = -1;
        rfl (j, 31, 0) {
            if (isOn(n, j) && cnt == 1) {
                second = j;
                break;
            }
            if (isOn(n, j) && cnt == 0) {
                first = j;
                cnt ++;
            }
        }

        if (second == -1) {
            cout << "1" << endl;
        }
        else if(first != second + 1) {
            int subt = (1 << first) + (1 << second);
            int add = (1 << first) + (1 << (second + 1));
            cout << min(n - subt, add - n) << endl;
        }
        else {
            cout << n - ((1 << first) + (1 << second));
        }
        */

        ll min_diff;
        min_diff = LLINF;

        rep(j, total){
            if(abs(num_with_two_set_bits[j] - n) < min_diff){
                min_diff = abs(num_with_two_set_bits[j] - n);
            }
        }

        cout << min_diff << endl;
    }

    return 0;
}