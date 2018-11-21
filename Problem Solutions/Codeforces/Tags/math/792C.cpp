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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt","w",stderr);
    #endif

    FAST_IO;
    
    string s;
    cin >> s;

    int n = slen(s);
    int dp[n][3]; // 1st index: prefix of string, second index: modulo 3 value
    // dp[i][j] is true if there exist a prefix of string from which after removing some digits we can get j after taking mod with 3
    fill (dp, 0);

    // string store[n][3];
    vector < vector <string> > store (n, vector <string> (3, ""));
    dp[0][dig(0) % 3]++;
    store[0][dig(0) % 3] = s[0];

    rep1 (i, n) {
        rep (j, 3) {
            // only for the current digit at s[i]
            dp[i][dig(i) % 3] = 1;
            if (store[i][dig(i) % 3].length() < 1)
            	store[i][dig(i) % 3] = s[i];

            if (dp[i - 1][j]) {
                // dont include the current digit at s[i]
                if (store[i - 1][j].length() >= store[i][j].length()) {
                	store[i][j] = store[i - 1][j];
                }

                // include the current digit at s[i]
                if (store[i - 1][j].length() > 0) {
                	string temp = store[i - 1][j] + s[i];
                	// trace1(temp);
                	if (store[i][(j*10 + dig(i)) % 3].length() <= temp.length())
                		store[i][(j*10 + dig(i)) % 3] = temp;
                	// trace1((j*10 + dig(i)) % 3);
                	// trace1(store[i][(j*10 + dig(i)) % 3]);
                }
            }

            // dont include the current digit at s[i]
            dp[i][j] |= dp[i - 1][j];

            // include the current digit at s[i]
            dp[i][(j*10 + dig(i)) % 3] |= dp[i - 1][j];
        }
    }

    int max_length = 0, ans = -1;
   	rep (i, n) {
   		if (store[i][0].length() > max_length) {
   			max_length = store[i][0].length();
   			ans = i;
   		}
   	}

    if (ans != -1) {
    	int i = 0, l = slen(store[ans][0]);
    	while (i < l - 1 && store[ans][0][i] == '0') {
    		i ++;
    	}
    	cout << store[ans][0].substr(i) << endl;
    }
    else {
    	cout << ans << endl;
    }

    return 0;
}