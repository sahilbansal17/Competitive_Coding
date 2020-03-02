#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

const int MAX = 200020; 
const ll MOD = 1000000007;

// https://github.com/sahilbansal17/Competitive_Coding/blob/master/Algorithms/Number-Theory/ncr_modulo_p.cpp
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

ll fact[MAX];
// Returns nCr % p using Fermat's little theorem.
ll nCrModP(ll n, ll r, ll p){
    // Base case
    if(r == 0)
        return 1;

    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}

int main(){

    FAST_IO;    

    ll t;
    cin >> t;

    ll n, m;

    // Fill factorial array so that we can find all factorial of r, n and n - r
   
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    while (t--) {
        cin >> n >> m;
        cout << nCrModP(n + m - 1, m, MOD) << endl;
    }

    return 0;
}