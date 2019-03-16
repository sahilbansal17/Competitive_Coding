#include <iostream>
#include <map>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

map <ll, ll> dp;

ll solve (ll t) {
    if (t < 12) {
        return t;
    }
    ll res = 0;
    
    if (dp[t/2] != 0)
        res += dp[t/2];
    else
        res += solve(t/2);
    
    if (dp[t/3] != 0)
        res += dp[t/3];
    else 
        res += solve(t/3);

    if (dp[t/4] != 0)
        res += dp[t/4];
    else
        res += solve(t/4);

    return dp[t] = res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    ll t;
    while (cin >> t) {
        ll res;
        res = solve (t);
        cout << res << endl;
    }

    return 0;
}