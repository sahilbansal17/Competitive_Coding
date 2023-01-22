#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cin >> grid[r][c];
    }
  }
}

void solve() {
  int n = 2;

  vector<vector<int> > grid;
  readGrid(grid, n, n);

  int mini = 101, maxi = 0;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      mini = min(mini, grid[r][c]);
      maxi = max(maxi, grid[r][c]);
    }
  }

  // check if mini and maxi are at the opposite corners
  int mini_r = -1, mini_c = -1, maxi_r = -1, maxi_c = -1;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == mini) {
        mini_r = r;
        mini_c = c;
      }
      if (grid[r][c] == maxi) {
        maxi_r = r;
        maxi_c = c;
      }
    }
  }

  if (mini_r == maxi_r || mini_c == maxi_c) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
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