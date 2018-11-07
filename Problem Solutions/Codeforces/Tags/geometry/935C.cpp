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
    const int MAX = 105;
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
    
    double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    // point C: (x1, y1), point P: (x2, y2), point Q: point on line PC extended touching the circle as far as possible
    // point W: midpoint of line PQ which will be the required center of access point

    // if center of flat is same as the point where Fafa is present 
    double res_x, res_y, res_r;
    if (x1 == x2 && y1 == y2) {
        // can choose any point on circle as Q, required radius, r = R/2
        res_r = R/2;
        res_x = (x1 + (x1 + R*0))/2; // x = x1 + r*cos(ø), Q_x = x1 (because, ø = 90)
        res_y = (y1 + (y1 + R*1))/2; // y = y1 + r*sin(ø), Q_y = y1 + R 
    }
    else if (x2*x2 + y2*y2 + x1*x1 + y1*y1 - 2*x1*x2 - 2*y1*y2 - R*R > 0) {
        // point P is outside the circle
        res_r = R;
        res_x = x1, res_y = y1;
    }
    else {
        // find equation of line PC
        double m = (y2 - y1)/(x2 - x1);
        double ang = atan(m);

        // find point Q on circle and line PC such that PQ is maximum
        double x11 = x1 + R*cos(ang), y11 = y1 + R*sin(ang);
        double x22 = x1 + R*cos(ang + PI), y22 = y1 + R*sin(ang + PI);
        double dist1 = sqrt(sqr(x11 - x2) + sqr(y11 - y2)); 
        double dist2 = sqrt(sqr(x22 - x2) + sqr(y22 - y2));

        // the result radius = PQ/2, and result center is at midpoint of PQ
        if (dist2 > dist1) {
            res_x = (x2 + x22)/2, res_y = (y2 + y22)/2;
            res_r = dist2/2;
        }
        else {
            res_x = (x2 + x11)/2, res_y = (y2 + y11)/2;
            res_r = dist1/2;
        }
    }

    cout << fixed;
    cout << setprecision(6) << res_x << " " << res_y << " " << res_r << endl;
    return 0;
}