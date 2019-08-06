#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

template <typename T> T power(T x, T y, ll m) {
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

class Solution {
 private:
  ll MOD;
 public:
  Solution() {
    MOD = 998244353;
  }
  ll solve(ll w, ll h) {
    ll res = power(2ll, w + h, MOD);
    return res; 
  }
};

int main() {

  FAST_IO;
  Solution solver;
  ll w, h;
  cin >> w >> h;

  cout << solver.solve(w, h);
  return 0;
}