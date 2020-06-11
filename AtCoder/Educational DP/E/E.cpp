#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
// #define MULTIPLE_TESTS 1

void solve() {
  int n, w;
  cin >> n >> w;
  vector<ll> wt(n), val(n);
  ll sum_val = 0;
  for (int i = 0; i < n; ++i) {
    cin >> wt[i] >> val[i];
    sum_val += val[i];
  }
  vector<ll> minWeight(sum_val + 1, 1e10);
  minWeight[0] = 0;
  for (int item = 0; item < n; ++item) {
    for (int value_already = sum_val - val[item]; value_already >= 0;
         --value_already) {
      minWeight[value_already + val[item]] =
          min(minWeight[value_already + val[item]],
              minWeight[value_already] + wt[item]);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= sum_val; ++i) {
    if (minWeight[i] <= w) {
      ans = max(ans, (ll)i);
    }
  }
  cout << ans << endl;
}
int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  while (t--) {
    solve();
  }

  return 0;
}