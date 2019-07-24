#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a) {
    sort(a.begin(), a.end());
    int k = min(a[n - 1], a[n - 2]) - 1;
    int ans = min(k, n - 2);
    return ans;
  }
};

int main() {

  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }

    Solution solver;
    cout << solver.solve(n, a) << endl;
  }
  return 0;
}