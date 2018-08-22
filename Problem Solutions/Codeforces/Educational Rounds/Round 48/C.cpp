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
    const ll MAX = 10010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n;
    cin >> n;

    vvi a(2, vi (n, 0));

    rep(i, 2){
        rep(j, n){
            cin >> a[i][j];
        }
    }

    /*/ ---Add '/' in the beginning of this line, before first '/' to uncomment ---
    rep(i, 2){
        rep(j, n){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    //*/

    vvll sum111(2, vll (n + 1, 0)), sum123(2, vll (n + 1, 0)), sum321(2, vll (n + 1, 0));

    rep(i, 2){
        rfl(j, n - 1, 0){
            // sum111[i][j] is simply the sum of elements from a[i][j] to a[i][n - 1]
            sum111[i][j] = sum111[i][j + 1] + 1LL * a[i][j];
            // sum123[i][j] is the sum having weightage of a[i][j] as j + 1, to a[i][n - 1] as n
            sum123[i][j] = sum123[i][j + 1] + (j + 1) * 1LL * a[i][j];
            // sum321[i][j] is the sum having weightage of a[i][n - 1] as 1, to a[i][n - (n - j)] as (n - j)
            sum321[i][j] = sum321[i][j + 1] + (n - j) * 1LL * a[i][j];
        }
    }

    /*/ ---Add '/' in the beginning of this line, before first '/' to uncomment ---
    rep(i, 2){
        cout << "Row " << i + 1 << ": " << endl;
        cout << "sum111: ";
        rep(j, n){
            cout << sum111[i][j] << " ";
        }
        cout << endl;

        cout << "sum123: ";
        rep(j, n){
            cout << sum123[i][j] << " ";
        }
        cout << endl;

        cout << "sum321: ";
        rep(j, n){
            cout << sum321[i][j] << " ";
        }
        cout << endl << endl;
    }
    //*/

    ll res = 0, current_zig_zag_sum = 0, current_total_sum = 0;
    int i = 0; // row_index
    /*  
        row_index is switched each time by taking xor with 1, since
        0 ^ 1 = 1 (0 --> 1)
        1 ^ 1 = 0 (1 --> 0)
    */

    int j = 0; // col_index
    while(j < n){
        // set current total sum to current zig zag sum
        current_total_sum = current_zig_zag_sum;
        // move to the end of the current row, by using sum123 and sum111
        current_total_sum += sum123[i][j] + j * 1LL * sum111[i][j];
        // move to the left of the another row, by using sum321 and sum111
        current_total_sum += sum321[i ^ 1][j] + (n + j) * 1LL * sum111[i ^ 1][j];

        // update the result
        res = max(current_total_sum, res);

        // calculate the next zig zag sum by including the next column
        current_zig_zag_sum += a[i][j] * 1LL * (2*j + 1);
        current_zig_zag_sum += a[i ^ 1][j] * 1LL * (2*j + 2);

        // update the variables
        j ++;
        i ^= 1;
    }

    // update the result by considering the weightage of a[0][0] = 0 and not 1
    // i.e. reduce weightage of each element by 1

    rep(j, n){
        res -= (a[0][j] + a[1][j]);
    }

    cout << res;
    return 0;
}