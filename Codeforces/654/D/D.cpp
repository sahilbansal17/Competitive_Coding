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
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}

template <typename T>
inline void printGrid(vector<vector<T>>& grid, int R, int C) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}
void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> ans(n, vector<int>(n, 0));
  vector<int> pos(n);
  iota(pos.begin(), pos.end(), 0);
  // printArray(pos);

  int levels = k / n;
  int rem = k % n;
  if (rem == 0) {
    cout << 0 << endl;
  } else {
    cout << 2 << endl;
  }
  // vector<int> row(n, 0), col(n, 0);
  for (int i = 0; i < n; ++i) {
    int p = pos[i];
    for (int j = 0; j < levels; ++j) {
      ans[i][(p + j) % n] = 1;
      // ++row[i];
      // ++col[(p + j) % n];
    }
    if (rem) {
      ans[i][(p + levels) % n] = 1;
      // ++row[i];
      // ++col[(p + levels) % n];
      --rem;
    }
  }
  // int a = *max_element(row.begin(), row.end());
  // int b = *min_element(row.begin(), row.end());

  printGrid(ans, n, n);
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