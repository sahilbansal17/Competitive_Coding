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

#define isOn(S, j) (S & (1ll << j))

// returns the number of zeroes at the end of the 
// binary representation of x
// if k zeroes, => x is divisible by 2^k
int zeroes_at_end(ll x){
    int cnt = 0;
    rep(i, 64){
        if(isOn(x, i)){
            return cnt;
        }
        cnt ++;
    }
    return cnt;
}

ll num_of_nodes;
string query;

ll solve(ll node, int q_idx, int len){

    if(q_idx == len){
        re node;
    }

    char q = query[q_idx];
    int zero = zeroes_at_end(node);

    // trace1(node);

    switch(q){
        case 'L': 
            if(zero > 0) re solve(node - (1ll << (zero - 1)), q_idx + 1, len);
            else re solve(node, q_idx + 1, len);
            break;
        case 'R':
            if(zero > 0) re solve(node + (1ll << (zero - 1)), q_idx + 1, len);
            else re solve(node, q_idx + 1, len);
            break;
        case 'U':
            if(node == ((num_of_nodes + 1) >> 1) ) re solve(node, q_idx + 1, len);
            else{
                ll add = node + (1ll << zero);
                ll subt = node - (1ll << zero);
                if(zeroes_at_end(add) == zero + 1){
                    re solve(add, q_idx + 1, len);
                }
                else{
                    re solve(subt, q_idx + 1, len);
                }
            }
            break;
    }
    return -1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int num_of_queries;
    cin >> num_of_nodes >> num_of_queries;

    ll node;
    rep(i, num_of_queries){
        cin >> node;
        cin >> query;

        cout << solve(node, 0, sz(query)) << endl;

        query.clear();
    }
    
    return 0;
}