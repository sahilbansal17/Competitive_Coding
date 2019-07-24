#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  pair<int, int> solve(int n, vector<int> a) {
    vector<int> b = a;
    sort(b.begin(), b.end());
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        if (l == -1) {
          l = i;
        } else {
          r = i;
        }
      }
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    bool possible = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        possible = false;
        break;
      }
    }
    pair<int, int> res;
    if (!possible) {
      res.first = -1;
      res.second = -1;
    } else if (l != -1) {
      res.first = l + 1;
      res.second = r + 1;
    } else {
      res.first = 1;
      res.second = 1;
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  pair<int, int> res = solver.solve(n, a);
  if (res.first == -1 && res.second == -1) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
    cout << res.first << " " << res.second << endl;
  }
  return 0;
}