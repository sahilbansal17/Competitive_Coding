#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  vector<int> solve(int n, int k, vector<ll> a) {
    vector<int> res;
    ll cur = 0;
    int copyK = k;
    for (int i = 0; i < n; ++i) {
      cur += a[i];
      if (cur & 1) {
        if (k > 1 || i == n - 1) {
          --k;
          res.push_back(i + 1);
          cur = 0;
        }
      }
    }
    /*/
    for (int i = 0; i < res.size(); ++i) {
      cerr << res[i] << " ";
    }
    cerr << endl;
    //*/
    if (res.size() != copyK) {
      res.clear();
      return res;
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int q;
  cin >> q;

  int n, k;
  for (int i = 0; i < q; ++i) {
    cin >> n >> k;
    vector<ll> a(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }
    Solution solver;
    vector<int> res = solver.solve(n, k, a);
    if (res.size() != 0) {
      cout << "YES" << endl;
      for (int j = 0; j < res.size(); ++j) {
        cout << res[j] << " ";
      }
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}