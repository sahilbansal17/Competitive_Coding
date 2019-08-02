#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int x, int y, vector<int> a) {
    for (int i = 0; i < n; ++i) {
      int k = i - 1;
      int ct = 0;
      bool possible = true;
      while (k >= 0 && ct < x) {
        if (a[i] >= a[k]) {
          possible = false;
          break;
        }
        ++ct;
        --k;
      }
      if (!possible) {
        continue;
      }
      k = i + 1;
      ct = 0;
      while (k < n && ct < y) {
        if (a[i] >= a[k]) {
          possible = false;
          break;
        }
        ++ct;
        ++k;
      }
      if (!possible) {
        continue;
      }
      return (i + 1);  
    }
    return -1;
  }
};

int main() {
  FAST_IO;
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, x, y, a);
  return 0;
}