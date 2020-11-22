#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};

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
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> grid;
  readGrid(grid, rows, cols);

  int count_negative = 0;
  int abs_sum = 0;
  int mini = INT_MAX;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (grid[r][c] < 0) {
        ++count_negative;
      }
      mini = min(mini, abs(grid[r][c]));
      abs_sum += abs(grid[r][c]);
    }
  }
  if (count_negative % 2 == 0) {
    cout << abs_sum << endl;
    return;
  }
  cout << abs_sum - 2*mini << endl;
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