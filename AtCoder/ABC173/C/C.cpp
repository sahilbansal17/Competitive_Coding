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
template <typename T>
inline void readGrid(vector<vector<T>>& grid, int R, int C) {
  grid.assign(R, vector<T>(C));
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> grid[i][j];
    }
  }
}

const int N = 6;
vector<int> row(N, 0), col(N, 0);
int tot = 0;
vector<vector<char>> grid;
int h, w, k;
ll ans = 0;
void check(vector<int> rows, vector<int> cols) {
  vector<vector<int>> done(h, vector<int>(w, 0));
  int curr = 0;
  for (int i = 0; i < rows.size(); ++i) {
    int cur = rows[i];
    for (int j = 0; j < w; ++j) {
      if (grid[cur][j] == '#' && !done[cur][j]) {
        ++curr;
        done[cur][j] = 1;
      }
    }
  }
  for (int i = 0; i < cols.size(); ++i) {
    int cur = cols[i];
    for (int j = 0; j < h; ++j) {
      if (grid[j][cur] == '#' && !done[j][cur]) {
        ++curr;
        done[j][cur] = 1;
      }
    }
  }
  if (tot - curr == k) {
    ++ans;
  }
}

void countAllNextCol(int cur, vector<int> rows, vector<int> cols) {
  if (cur == w) {
    check(rows, cols);
    return;
  }
  countAllNextCol(cur + 1, rows, cols);
  cols.push_back(cur);
  countAllNextCol(cur + 1, rows, cols);
}
void countAllFirstRow(int cur, vector<int> rows) {
  if (cur == h) {
    vector<int> tmp;
    countAllNextCol(0, rows, tmp);
    return;
  }
  countAllFirstRow(cur + 1, rows);
  rows.push_back(cur);
  countAllFirstRow(cur + 1, rows);
}
void solve() {
  cin >> h >> w >> k;

  readGrid(grid, h, w);

  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (grid[r][c] == '#') {
        ++row[r];
        ++col[c];
        ++tot;
      }
    }
  }

  vector<int> tmp;
  countAllFirstRow(0, tmp);

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