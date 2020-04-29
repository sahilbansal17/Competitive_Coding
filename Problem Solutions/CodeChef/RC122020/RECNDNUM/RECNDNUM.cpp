#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const ll MOD = 1e9 + 7;
/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power(ll x, ll y, ll p){
    ll res = 1;     
    x = x % p;  
    while (y > 0){
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p (used Fermat's little theorem)
ll modInverse(ll n, ll p){
    return power(n, p-2, p);
}
void solve() {
    ll n, k;
    cin >> n >> k;

    if (n == 0) {
        if (k == 1) {
            cout << "0" << endl;
            return;
        }
        --k;
        ll res = (k*(k + 1)) % MOD;
        cout << res << endl;
        return ;
    }

    ll fin = ceil((1.0*k - 1)/2.0);
    ll rem = k - (1 + (fin - 1)*2);
    ll shift = (n - 1) + fin;
    
    // ll m2 = modInverse(2, MOD);

    ll done = (shift*(shift + 1)) % MOD;
    if (rem == 1) {
        done += n;
        done %= MOD;
    } else if (rem == 2) {
        done += (2*(shift + 1)) % MOD;
        done %= MOD;
        done -= n;
        done += MOD;
        done %= MOD;
    }
    cout << done << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}