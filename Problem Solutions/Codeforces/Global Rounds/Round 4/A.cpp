#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  void solve(int n, vector<int> a) {
    int sum = a[0], co = a[0];
    vector<int> res;
    res.push_back(1);
    for (int i = 1; i < n; ++i) {
      if (a[0] >= 2*a[i]) {
        res.push_back(i + 1);
        co += a[i];
      }
      sum += a[i];
    }
    if (co <= sum/2) {
      cout << "0";
      return;
    }
    if (a[0] > sum/2) {
      cout << "1" << endl;
      cout << "1" << endl;
    } else {
      cout << res.size() << endl;
      for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
      }
    }
  }
};

int main() {

  FAST_IO;
  Solution solver;
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  solver.solve(n, a);
  return 0;
}