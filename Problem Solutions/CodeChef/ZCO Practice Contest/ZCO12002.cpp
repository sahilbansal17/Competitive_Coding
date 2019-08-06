#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<pair<int, int>> contests, vector<int> v, vector<int> w) {
    int x = v.size();
    int y = w.size();
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int start = contests[i].first;
      int end = contests[i].second;
      // cerr << start << " " << end << " ";
      int idx1 = lower_bound(v.begin(), v.end(), start) - v.begin();
      if (idx1 == x) {
        --idx1; // we want smaller value than start
      }
      int idx2 = lower_bound(w.begin(), w.end(), end) - w.begin();
      if (v[idx1] > start) {
        --idx1; // we want smaller value than start
      }
      if (idx1 < 0 || idx2 == y) {
        // cerr << endl;
        continue;
      }
      // cerr << v[idx1] << " " << w[idx2] << endl;
      res = min(res, w[idx2] - v[idx1] + 1);
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n, x, y;
  cin >> n >> x >> y;

  vector<pair<int, int>> contests(n);
  for (int i = 0; i < n; ++i) {
    cin >> contests[i].first >> contests[i].second;
  }

  vector<int> v(x), w(y);
  for (int i = 0; i < x; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < y; ++i) {
    cin >> w[i];
  }

  Solution solver;
  cout << solver.solve(n, contests, v, w);
  return 0;
}