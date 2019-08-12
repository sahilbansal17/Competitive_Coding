/*
 * https://www.codechef.com/AUG19A/problems/ZOMCAV
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  bool solve(int n, vector<int> c, vector<int> h) {
    vector<int> radiationLevels(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int start = i - c[i];
      int end = i + c[i] + 1;
      if (start < 0) {
        start = 0;
      }
      if (end > n) {
        end = n;
      }
      radiationLevels[start] += 1;
      radiationLevels[end] -= 1;
    }
    // prefix sum computation
    for (int i = 1; i < n; ++i) {
      radiationLevels[i] += radiationLevels[i - 1];
    }

    radiationLevels.pop_back();
    #ifdef DEBUG
    for (auto it: radiationLevels) {
      cerr << it << " ";
    }
    cerr << endl;
    #endif

    sort(radiationLevels.begin(), radiationLevels.end());
    sort(h.begin(), h.end());

    return (radiationLevels == h);
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<int> c(n), h(n);
    for (int j = 0; j < n; ++j) {
      cin >> c[j];
    }
    for (int j = 0; j < n; ++j) {
      cin >> h[j];
    }

    Solution solver;
    if (solver.solve(n, c, h)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}