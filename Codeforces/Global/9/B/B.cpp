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
template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }
}

template <typename T>
inline void printGrid(vector<vector<T>>& grid) {
  int R = grid.size();
  int C = grid[0].size();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid;
  readGrid(grid, n, m);
  vector<vector<int>> arr(n, vector<int>(m, 0));
  arr[0][0] = 2;
  arr[n - 1][0] = 2;
  arr[0][m - 1] = 2;
  arr[n - 1][m - 1] = 2;
  for (int c = 1; c < m - 1; ++c) {
    arr[0][c] = 3;
    arr[n - 1][c] = 3;
  }
  for (int r = 1; r < n - 1; ++r) {
    arr[r][0] = 3;
    arr[r][m - 1] = 3;
  }
  for (int r = 1; r < n - 1; ++r) {
    for (int c = 1; c < m - 1; ++c) {
      arr[r][c] = 4;
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (arr[r][c] < grid[r][c]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  printGrid(arr);
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