#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

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
 
// Returns nCr % p using Fermat's little theorem.
ll nCrModP(ll n, ll r, ll p){
   // Base case
   if(r == 0)
      return 1;
    // Fill factorial array so that we can find all factorial of r, n and n - r
    ll fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}

int main () {
    int n, m;
    cin >> n >> m;

    ll ans = nCrModP(n + 2*m - 1, 2*m, MOD);
    cout << ans << endl;
    return 0;
}