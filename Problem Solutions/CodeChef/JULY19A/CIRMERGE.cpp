/*
 * CIRCULAR MERGING
 * https://www.codechef.com/JULY19A/problems/CIRMERGE
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MAX = 9223372036854775807LL;
class Solution {
 public:
  ll solve(int n, vector<ll> &a) {
    vector<vector <ll>> dp(n, vector<ll>(n, MAX));
    vector<ll> pre(n, 0);
    pre[0] = a[0];
    for (int i = 0; i < n; i++) {
      dp[i][i] = 0;
      if (i != 0) {
        pre[i] = pre[i - 1] + a[i];
      }
    }

    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      dp[i][j] = a[i] + a[j];
    }
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i < n; i++) {
        int j = (i + len - 1) % n;
        int k = i;
        while (k != j) {
          ll preSum;
          if (j > i) {
            if (i >= 1) {
              preSum = pre[j] - pre[i - 1];
            } else {
              preSum = pre[j];
            }
          } else {
            preSum = pre[j] + (pre[n - 1] - pre[i - 1]);
          }
          if (k == i) {
            dp[i][j] = min(dp[i][j],
                          preSum + (dp[i][i] + dp[(i + 1) % n][j]));
          } else if ((k + 1) % n == j) {
            dp[i][j] = min(dp[i][j],
                          preSum + (dp[i][k] + dp[j][j]));
          } else {
            dp[i][j] = min(dp[i][j],
                          preSum + (dp[i][k] + dp[(k + 1) % n][j]));
          }
          k ++;
          k %= n;
        }
      }
    }

    //*/
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        cerr << dp[i][j] << " ";
      }
      cerr << endl;
    }
    //*/
    
    ll ans = MAX;
    for (int i = 0; i < n; i ++) {
      int j = (i + n - 1) % n;
      ans = min(ans, dp[i][j]);
    }
    return ans;
  }
};

int main() {

  FAST_IO;
  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  Solution solver;

  int t;
  cin >> t;
  for(int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    ll ans = solver.solve(n, a);
    cout << ans << endl;
  }

  return 0;
}