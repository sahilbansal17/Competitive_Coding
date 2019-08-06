#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(int n, int k, vector<int> a) {
    if (n == k) {
      return 0;
    }
    if (k == 1) {
      return a[n - 1] - a[0];
    }
    vector<int> diff;
    for (int i = 1; i < n; ++i) {
      diff.push_back(a[i - 1] - a[i]);
    }
    sort(diff.begin(), diff.end());

    ll res = 1ll*a[n - 1] - 1ll*a[0];
    for (int i = 0; i < k - 1; ++i) {
      res += 1ll*diff[i];
    }

    return res;
  }
};

int main() {

  FAST_IO;
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  Solution solver;
  cout << solver.solve(n, k, a) << endl;
  return 0;
}