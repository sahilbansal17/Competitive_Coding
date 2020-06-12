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
#define MULTIPLE_TESTS 1

int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};

template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }
}

inline bool safeChecker(int x, int y, int R, int C) {
  if (x < 0 || y < 0 || x >= R || y >= C) {
    return false;
  }
  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid;
  readGrid(grid, n, m);

  int ans = 0;
  vector<vector<int>> cnt(2, vector<int>(n + m - 1, 0));
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      ++cnt[grid[r][c]][r + c];
    }
  }

  int tot = n + m - 1;
  for (int i = 0; i < tot / 2; ++i) {
    int ones = cnt[1][i] + cnt[1][tot - i - 1];
    int zero = cnt[0][i] + cnt[0][tot - i - 1];
    ans += min(ones, zero);
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