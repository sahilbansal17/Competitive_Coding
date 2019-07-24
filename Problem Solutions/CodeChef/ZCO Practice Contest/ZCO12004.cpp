#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a) {
    // consider the linear array a
    vector<int> dp1(n, INT_MAX); // a[i] is included for dp1[i]
    dp1[0] = a[0];
    if (n > 1) {
      dp1[1] = a[1]; // first person not included
    }
    for (int i = 2; i < n; ++i) {
      dp1[i] = a[i] + min(dp1[i - 1], dp1[i - 2]);
    }

    // in dp1[n - 1], first person not included
    // but first person may be included in the final answer
    reverse(a.begin(), a.end());

    // in dp2[n - 1], a[n - 1] is a[0] of original array
    vector<int> dp2(n, INT_MAX);
    dp2[0] = a[0];
    if (n > 1) {
      dp2[1] = a[1]; // last person(a[0] in reversed array) not included
    }
    for (int i = 2; i < n; ++i) {
      dp2[i] = a[i] + min(dp2[i - 1], dp2[i - 2]);
    }

    // consider minimum for both original and reversed arrays
    return min(dp2[n - 1], dp1[n - 1]);
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
  cout << solver.solve(n, a);
  return 0;
}