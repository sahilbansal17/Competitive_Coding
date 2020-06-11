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

vector<vector<ll>> cache;
ll knapsack(int cur, int used, int W, const vector<ll>& wt,
            const vector<ll>& val) {
  if (cur == wt.size()) {
    return 0;
  }
  if (cache[cur][used] != -1) {
    return cache[cur][used];
  }
  // don't consider this item
  ll option1 = knapsack(cur + 1, used, W, wt, val);
  // consider this item
  ll option2 = 0;
  if (used + wt[cur] <= W) {
    option2 = knapsack(cur + 1, used + wt[cur], W, wt, val) + val[cur];
  }
  return cache[cur][used] = max(option1, option2);
}
void solve() {
  int n, w;
  cin >> n >> w;
  vector<ll> wt(n), val(n);
  for (int i = 0; i < n; ++i) {
    cin >> wt[i] >> val[i];
  }
  cache.assign(n, vector<ll>(w + 1, -1));
  cout << knapsack(0, 0, w, wt, val) << endl;
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