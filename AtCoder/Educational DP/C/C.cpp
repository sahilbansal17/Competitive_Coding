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

vector<vector<int>> cache;
int recursive(int cur, int prev, const vector<vector<int>>& cost) {
  if (cur == cost.size()) {  // all done
    return 0;
  }
  if (prev != -1 && cache[cur][prev] != -1) {
    return cache[cur][prev];
  }
  int points = 0;
  // consider only ones with different prev
  for (int j = 0; j < 3; ++j) {
    if (j != prev) {
      points =
          max(points, recursive(cur + 1, j, cost) + cost[cur][j]);  // prev = j
    }
  }
  if (prev == -1) {
    return points;
  }
  return cache[cur][prev] = points;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(3));  // n*3 cost matrix
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> cost[i][j];
    }
  }
  cache.assign(n, vector<int>(3, -1));
  int ans = recursive(0, -1, cost);
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