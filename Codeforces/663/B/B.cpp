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
  int R, C;
  cin >> R >> C;

  vector<vector<char>> grid;
  readGrid(grid, R, C);

  int cnt = 0;
  for (int r = 0; r < R - 1; ++r) {
    if (grid[r][C - 1] != 'D') {
      ++cnt;
    }
  }
  for (int c = 0; c < C - 1; ++c) {
    if (grid[R - 1][c] != 'R') {
      ++cnt;
    }
  }
  cout << cnt << endl;
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