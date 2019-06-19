#include <bits/stdc++.h>

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

vector <ll> factorize(ll x) {
    ll a = 2;
    vector <ll> res;
    while (a <= sqrt(x)) {
        if (x % a == 0) {
            res.push_back(a);
            if (a != (x/a))
                res.push_back(x/a);
        }
        a ++;
    }
    sort(res.begin(), res.end());
    return res;
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

    int n;
    while (t --) {
        cin >> n;
        vector <ll> a(n, 0);
        for (int j = 0; j < n; j ++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());

        ll res = a[0]*a[n - 1];

        vector <ll> facs = factorize(res);
        for (int i = 0; i < facs.size(); i ++) {
            if (facs[i] != a[i]) {
                res = -1;
                break;
            }
        }

        cout << res << endl;
    }
    return 0;
}