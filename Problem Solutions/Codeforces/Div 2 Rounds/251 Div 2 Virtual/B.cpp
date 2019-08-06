#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve (int n, int x, vector<ll> c) {
    sort(c.begin(), c.end());
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      if (x == 1) {
        res += c[i];
      } else {
        res += x*c[i];
        --x;
      }
    }
    return res;
  }
};

int main() {

  FAST_IO;  
  Solution solver;
  
  int n, x;
  cin >> n >> x;

  vector<ll> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  cout << solver.solve(n, x, c);
  return 0;
}