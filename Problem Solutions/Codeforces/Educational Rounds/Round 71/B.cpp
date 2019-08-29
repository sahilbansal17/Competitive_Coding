#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int MAX = 100;

int main() {
  FAST_IO;  
  int n, m;
  cin >> n >> m;

  int a[MAX][MAX], b[MAX][MAX];

  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        int cnt = 0;
        if (j + 1 < m && a[i][j + 1] == 1) {
          ++cnt;
        }
        if (i + 1 < n && a[i + 1][j] == 1) {
          ++cnt;
        }
        if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == 1) {
          ++cnt;
        }
        if (cnt == 3) {
          res.push_back({i + 1, j + 1});
          b[i][j] = 1;
          b[i + 1][j] = 1;
          b[i][j + 1] = 1;
          b[i + 1][j + 1] = 1;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << res.size() << endl;
  for (auto it: res) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}