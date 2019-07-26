#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

// #define DEBUG 1
class Solution {
 public:
  ll solve(int n, vector<ll> a) {
    vector<ll> diff(n - 1);
    vector<ll> invertedDiff(n - 1);
    bool neg = false;
    for (int i = 0; i < n - 1; ++i) {
      if (!neg) {
        diff[i] = abs(a[i] - a[i + 1]);
        invertedDiff[i] = -1*diff[i];
      } else {
        diff[i] = -1*abs(a[i] - a[i + 1]);
        invertedDiff[i] = -1*diff[i];
      }
      neg = !neg;
    }
    ll sum1 = 0, sum2 = 0, maxSum1 = 0, maxSum2 = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (sum1 + diff[i] < 0) {
        sum1 = 0;
      } else {
        sum1 = sum1 + diff[i];
      }
      if (sum2 + invertedDiff[i] < 0) {
        sum2 = 0;
      } else {
        sum2 = sum2 + invertedDiff[i];
      }
      maxSum1 = max(sum1, maxSum1);
      maxSum2 = max(sum2, maxSum2);
    }
    return max(maxSum1, maxSum2);
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, a) << endl;
  return 0;
}