#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int k, string &s) {
    vector<vector<int>> matched(n, vector<int>(3, 0));
    string pat = "RGB";
    int p = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == pat[p]) {
        matched[i][0] = 1;
      } else if (s[i] == pat[(p + 1) % 3]) {
        matched[i][1] = 1;
      } else if (s[i] == pat[(p + 2) % 3]) {
        matched[i][2] = 1;
      }
      p = (p + 1) % 3;
    }
    int res = INT_MIN;
    int count[3] = {0};
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < 3; ++j) {
        count[j] += matched[i][j];
      }
    }
    for (int i = 0; i < 3; ++i) {
      res = max(res, count[i]);
    }
    for (int i = k; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        count[j] += matched[i][j];
        count[j] -= matched[(i - k)][j];
        res = max(res, count[j]);
      }
    }
    return k - res;
  }
};

int main() {

  FAST_IO;
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    Solution solver;
    cout << solver.solve(n, k, s) << endl;
  }
  return 0;
}