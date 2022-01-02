#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

void solve() {
  int n, l, r;

  cin >> n;
  vector<pair<int, int> > ranges;
  vector<vector<bool> > visited(n + 1, vector<bool> (n + 1));
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    ranges.push_back({ l, r });
    visited[l][r] = true;
  }

  for (int i = 0; i < n; ++i) {
    int l = ranges[i].first;
    int r = ranges[i].second;
    for (int d = l; d <= r; ++d) {
      if ((d == l || visited[l][d - 1]) && (d == r || visited[d + 1][r])) {
        cout << l << " " << r << " " << d << endl;
        break;
      }
    }
  }
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