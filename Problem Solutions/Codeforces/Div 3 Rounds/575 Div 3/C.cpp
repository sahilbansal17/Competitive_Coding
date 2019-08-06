#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  vector<int> solve(int n, vector<vector<int>> robots) {
    vector<int> res;
    int xleft = INT_MAX, yleft = INT_MAX;
    int xright = INT_MAX, yright = INT_MAX;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
      if (robots[i][2] == 0) { // left
        if (xleft == INT_MAX) {
          xleft = robots[i][0];
        } else {
          xleft = max(xleft, robots[i][0]);
        }
      }
      if (robots[i][3] == 0) { // up
        if (yright == INT_MAX) {
          yright = robots[i][1];
        } else {
          yright = min(yright, robots[i][1]);
        }
      }
      if (robots[i][4] == 0) { // right
        if (xright == INT_MAX) {
          xright = robots[i][0];
        } else {
          xright = min(xright, robots[i][0]);
        }
      }
      if (robots[i][5] == 0) { // down
        if (yleft == INT_MAX) {
          yleft = robots[i][1];
        } else {
          yleft = max(yleft, robots[i][1]);
        }
      }
    }
    // cerr << xleft << " " << xright << endl;
    // cerr << yleft << " " << yright << endl;
    // cerr << possible << endl;
    if ((xleft != INT_MAX && xright != INT_MAX && xleft > xright)
      ||(yleft != INT_MAX && yright != INT_MAX && yleft > yright)) {
      possible = false;
    }
    if (!possible) {
      res.push_back(0);
      return res;
    }
    int xres = 100000, yres = 100000;
    if (xleft != INT_MAX) {
      xres = xleft;
    }
    if (xright != INT_MAX) {
      xres = xright;
    }
    if (yleft != INT_MAX) {
      yres = yleft;
    }
    if (yright != INT_MAX) {
      yres = yright;
    }
    res.push_back(1);
    res.insert(res.end(), {xres, yres});
    return res;
  }
};

int main() {

  FAST_IO;
  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;

    vector<vector<int>> robots(n, vector<int>(6));
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < 6; ++j) {
        cin >> robots[k][j];
      }
    }

    Solution solver;
    vector<int> res = solver.solve(n, robots);
    for(int j = 0; j < res.size(); ++j) {
      cout << res[j] << " ";
    }
    cout << endl;
  }
  return 0;
}