/*
 * https://www.codechef.com/AUG19A/problems/MSNSADM1
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a, vector<int> b) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res = max(res, max(a[i]*20 - b[i]*10, 0));
    }
    return res;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }
    for (int j = 0; j < n; ++j) {
      cin >> b[j];
    }
    Solution solver;
    cout << solver.solve(n, a, b) << endl;
  }
  
  return 0;
}