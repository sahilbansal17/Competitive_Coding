#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a) {
    vector<int> dp(n, INT_MAX); // dp[i] is the min sum ending at a[i]
    for (int i = 0; i < n; ++i) {
      dp[i] = a[i];
      int prevMin = -1;
      if (i - 3 < 0) {
        // i = 0, 1, 2
        continue;
      }
      for (int j = i - 1; j >= 0 && i - j <= 3; --j) {
        if (prevMin == -1) {
          prevMin = dp[j];
        } else {
          prevMin = min(prevMin, dp[j]);
        }
      }
      dp[i] += prevMin;
    }
    int res = -1;
    for (int j = n - 1; j >= 0 && n - 1 - j <= 2; --j) {
      if (res == -1) {
        res = dp[j];
      } else {
        res = min(res, dp[j]);
      }
    }
    /*/
    for (int i = 0; i < n; ++i) {
      cerr << dp[i] << " " ;
    }
    //*/
    return res;
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, a);
  return 0;
}