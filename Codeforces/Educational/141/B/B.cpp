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
  int n;
  cin >> n;

  int l = 1, h = n*n;
  bool flag = true;

  vector<vector<int> > res(n, vector<int>(n, 0));

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (flag) {
        res[r][c] = l++;
      } else {
        res[r][c] = h--;
      }
      flag ^= 1;
    }
    if (r & 1) {
      reverse(res[r].begin(), res[r].end());
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      cout << res[r][c] << " ";
    }
    cout << endl;
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