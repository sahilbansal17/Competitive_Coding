// program to compute nCr modulo a prime no. p, greater than n

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

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
    fl(i, 1, n + 1){
        fact[i] = (fact[i - 1] * i) % p;
    }
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}
int main(){

    cout << nCrModP(10, 2, 13);

    // 10C2 is 45 and 45 % 13 = 6 
    return 0;
}