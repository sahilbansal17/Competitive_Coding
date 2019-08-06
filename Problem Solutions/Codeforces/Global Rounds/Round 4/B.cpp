#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(string &s) {
    int n = s.length();
    vector<int> left(n, 0), right(n, 0);
    int cc = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'v') {
        ++cc;
      } else {
        if (cc > 1) {
          cnt += (cc - 1);
        }
        cc = 0;
        left[i] = cnt;
      }
    }

    cnt = 0;
    cc = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'v') {
        ++cc;
      } else {
        if (cc > 1) {
          cnt += (cc - 1);
        }
        cc = 0;
        right[i] = cnt;
      }
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'o') {
        res += 1ll * left[i] * right[i];
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   cerr << right[i] << " ";
    // }
    // cerr << endl;

    return res;
  }
};

int main() {

  FAST_IO;
  string s;
  cin >> s;

  Solution solver;
  cout << solver.solve(s) << endl;
  return 0;
}