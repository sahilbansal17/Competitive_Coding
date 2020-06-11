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

const ll MOD = 1e9 + 7;
void solve() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid;
  readGrid(grid, h, w);
  vector<vector<ll>> ways(h, vector<ll>(w, 0));
  ways[0][0] = 1;
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (grid[r][c] == '#') {
        continue;  // no way to reach here
      }
      if (safeChecker(r - 1, c, h, w)) {  // from up
        ways[r][c] += ways[r - 1][c];
        ways[r][c] %= MOD;
      }
      if (safeChecker(r, c - 1, h, w)) {  // from left
        ways[r][c] += ways[r][c - 1];
        ways[r][c] %= MOD;
      }
    }
  }
  cout << ways[h - 1][w - 1] << endl;
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
