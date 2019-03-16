#include <iostream>
#include <map>
#include <vector>

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

ll ncr(ll n, ll r) {
    ll p = 1, k = 1;
    if (n - r < r) {
        r = n - r;
    } 

    while (r) {
        p *= n;
        k *= r;
        n -- ;
        r -- ;
        ll m = gcd(p, k);
        p /= m;
        k /= m;
    }

    return p;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t;
    cin >> t;

    ll n, k;
    for (int i = 0; i < t; i ++) {
        cin >> n >> k;
        cout << ncr(n - 1, k - 1) << endl;
    }

    return 0;
}