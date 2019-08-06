#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    int res = 0;

    vector<vector<int>> horizontal(n, vector<int> (m, 0));
    vector<vector<int>> vertical(n, vector<int> (m, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 1) {
          if (j >= 1) {
            horizontal[i][j] = 1 + horizontal[i][j - 1];
          } else {
            horizontal[i][j] = 1;
          }
        } else if (j >= 1) {
          horizontal[i][j] = horizontal[i][j - 1];
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[j][i] == 1) {
          if (j >= 1) {
            vertical[j][i] = 1 + vertical[j - 1][i];
          } else {
            vertical[j][i] = 1;
          }
        } else if (j >= 1) {
          vertical[j][i] = vertical[j - 1][i];
        }
      }
    }

    #ifdef DEBUG
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cerr << horizontal[i][j] << " ";
      }
      cerr << endl;
    }
    cerr << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cerr << vertical[i][j] << " ";
      }
      cerr << endl;
    }
    cerr << endl;
    #endif

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int cur = 0;
        if (a[i][j] == 0) {
          // right count
          cur += ((horizontal[i][m - 1] - horizontal[i][j]) > 0) ? 1 : 0;
          // left count
          if (j >= 1) {
            cur += ((horizontal[i][j - 1]) > 0) ? 1 : 0;
          }
          // up count
          if (i >= 1) {
            cur += ((vertical[i - 1][j]) > 0) ? 1 : 0;
          }
          // down count
          cur += ((vertical[n - 1][j] - vertical[i][j]) > 0) ? 1 : 0;
        }
        res += cur;
        #ifdef DEBUG
        if (cur > 0) {
          cerr << i << " " << j << ": " << cur << endl;
        }
        #endif
      }
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  Solution solver;
  cout << solver.solve(a) << endl;
  return 0;
}