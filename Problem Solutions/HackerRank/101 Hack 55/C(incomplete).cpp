#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
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
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i<(b); i++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a);i>=(b);i--)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(),(v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define MOD             1000000007
    #define MAX             100010
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          ((x).begin(), (x).end())
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
    
int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n;

    cin >> n;

    vi x(n, 0);
    vi y(n, 0);
    vpii pts, pts2;

    rep(i, n){
        cin >> x[i];
    }
    rep(i, n){
        cin >> y[i];
    }

    rep(i, n){
        pts.pb(mp(y[i], x[i]));
        pts2.pb(mp(x[i], y[i])); 
    }

    srt(pts);
    srt(pts2);

    /*/
    rep(i, pts.size()){
        cout << pts[i].F << " " << pts[i].S.F << " " << pts[i].S.S << "\n";
    }
    //*/
    set < pii > new_pt;
    int res = 0;
    rep(i, pts.size()){
        int c_y = pts[i].F;
        int flag = 1;
        int small = pts[i].S, large;
        while(i < pts.size() - 1 && pts[i + 1].F == c_y){
            large = pts[i + 1].S;
            fl(k, small, large - 1){
                // cout << "\n";
                // cout << c_y << " " << k + 1 << "\n";
                // manhattan_dist = abs(k + 1) + abs(c_y);
                new_pt.insert(mp(k + 1, c_y));
            }
            small = large;
            i ++;
            flag = 0;
        }
        if(flag == 0){
            i --;
        }
    }
    // cout << pts_y.size();
    

    /*/
    rep(i, pts2.size()){
        cout << pts2[i].F << " " << pts2[i].S.F << " " << pts2[i].S.S << "\n";
    }
    //*/

    // cout << "\n";
    rep(i, pts2.size()){
        int c_x = pts2[i].F;
        int flag = 1;
        int small = pts2[i].S, large;
        while(i < pts2.size() - 1 && pts2[i + 1].F == c_x){
            large = pts2[i + 1].S;
            // cout << small << " " << large << "\n";
            fl(k, small, large - 1){
                // cout << "\n";
                // cout << c_x << " " << k + 1 << "\n";
                // manhattan_dist = abs(k + 1) + abs(c_x);
                new_pt.insert(mp(c_x, k + 1));
            }
            small = large;
            i ++;
            flag = 0;
        }
        if(flag == 0){
            i --;
        }
    }

    cout << new_pt.size() ;    
    return 0;
}