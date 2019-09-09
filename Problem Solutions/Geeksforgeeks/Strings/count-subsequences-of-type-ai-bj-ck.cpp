/*
 * https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

ll pow2(ll a) {
  ll res = 1;
  ll x = 2;
  while (a) {
    if (a & 1) {
      res *= x;
    }
    a >>= 1;
    x *= x;
  }
  return res;
}

int main(){
  FAST_IO;    

  ll t;
  cin >> t;

  while (t --) {
    string s;
    cin >> s;

    int n = s.length();
    vector<ll> cntC(n, 0);
    if (s[n - 1] == 'c') {
      ++cntC[n - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == 'c') {
        cntC[i] = 1 + cntC[i + 1];
      } else {
        cntC[i] = cntC[i + 1];
      }
    }

    ll mulA = 1;
    ll mulB = 1;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        mulB = 1;
        for (int j = i + 1; j < n; ++j) {
          if (s[j] == 'b') {
            res += (mulA * mulB) * (pow2(cntC[j]) - 1);
            mulB *= 2;
          }
        }
        mulA *= 2;
      }
    }
    cout << res << endl;
  }
  return 0;
}