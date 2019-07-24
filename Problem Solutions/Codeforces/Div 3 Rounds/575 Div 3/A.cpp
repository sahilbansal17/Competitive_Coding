#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  void solve(int q) {
    ll a, b, c;
    ll res;
    for (int i = 0; i < q; ++i) {
      cin >> a >> b >> c;
      res = a + b + c;
      if (res & 1) {
        --res;
      }
      cout << res/2 << endl;
    }
  }
};

int main() {

  FAST_IO;
  int q;
  cin >> q;

  Solution solver;
  solver.solve(q);
  return 0;
}