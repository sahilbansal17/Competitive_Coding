#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  bool solve(int n, vector<int> a) {
    if (a[0] == n) {
      for (int i = 1; i < n; ++i) {
        if (a[i] != n - i) {
          return false;
        }
      }
    }
    if (a[n - 1] == n) {
      for (int i = n - 2; i >= 0; --i) {
        if (a[i] != i + 1) {
          return false;
        }
      }
    }
    int idx = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] == n) {
        idx = i;
      }
    }

    int i = idx - 1, j = idx + 1;
    int k = n - 1;
    while (k != 0) {
      if (i >= 0 && a[i] == k) {
        // cerr << k << " ";
        --i;
      } else if (j < n && a[j] == k) {
        // cerr << k << " ";
        ++j;
      } else {
        return false;
      }
      --k;
    }

    return true;
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
  if (solver.solve(n, a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}