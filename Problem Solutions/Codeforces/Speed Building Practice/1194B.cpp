#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int m, vector<vector<char>> im) {
    vector<int> rowCount(n, 0);
    vector<int> colCount(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (im[i][j] == '*') {
          rowCount[i] ++;
          colCount[j] ++;
        }
      }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int currentPainted = rowCount[i] + colCount[j];
        if (im[i][j] == '*') {
          currentPainted --;
        }
        res = min(res, (n + m - 1) - currentPainted);
      }
    }
    return res;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  Solution solver;  
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> image(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> image[i][j];
      }
    }
    cout << solver.solve(n, m, image) << endl;
  }
  return 0;
}