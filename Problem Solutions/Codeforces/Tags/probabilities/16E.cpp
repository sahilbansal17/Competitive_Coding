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
    const int MAX = 18;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

double ans[1 << MAX], a[MAX][MAX];

int countSetBits (int mask) {
    /*/
    int cnt = 0;
    while (mask) {
        cnt += (mask & 1);
        mask >>= 1;
    }
    return cnt;
    //*/

    return __builtin_popcount(mask); // inbuilt function to count set bits
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;
    
    int n;
    cin >> n;

    rep (i, n) {
        rep (j, n) {
            cin >> a[i][j]; // prob of fish i eating fish j
        }
    }

    // if i-th bit is set in mask, => i-th fish is alive
    // initially all the fish are alive => n set-bits
    int mask = (1 << n) - 1;
    ans[mask] = 1; // probabiity of this state is 1

    // trace1(mask);

    // for every pair of 2 fishes which are alive, one of them eats the other one
    // and the mask is updated 

    // O(n^2 * 2^n) => all possible pairs in a mask * no of masks possible 

    rfl (mask, (1 << n) - 1, 1) { 
        rep (eater, n) {
            // if eater is alive in the mask
            if (mask & (1 << eater)) {
                rep (dier, n) {
                    // if dier is alive in the mask and not the same as eater
                    if (dier != eater && (mask & (1 << dier))) {

                        // no of alive fishes 
                        int cnt = countSetBits (mask);

                        // unset the dier bit
                        int next_mask = mask ^ (1 << dier);

                        // udpate the probability of the next mask
                        ans[next_mask] += ans[mask] * a[eater][dier] / ((cnt * (cnt - 1))/2);
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(6) ;
    rep (i, n) {
        cout << ans[1 << i] << " ";
    }
    return 0;
}