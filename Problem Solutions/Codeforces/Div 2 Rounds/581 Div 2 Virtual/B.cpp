#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  pair<int, int> solve(int n, int l, int r) {
    pair<int, int> res;
    int minSum = 0, maxSum = 0;
    int cur = 1;    
    for (int i = 0; i < l; ++i) {
      minSum += cur;
      cur *= 2;
    }
    for (int i = 0; i < n - l; ++i) {
      minSum += 1;
    }
    res.first = minSum;

    cur = 1;
    for (int i = 0; i < r; ++i) {
      maxSum += cur;
      cur *= 2;
    }
    cur /= 2;
    for (int i = 0; i < n - r; ++i) {
      maxSum += cur;
    }
    res.second = maxSum;
    return res;
  }
};

int main() {
  FAST_IO;
  int n, l, r;
  cin >> n >> l >> r;

  Solution solver;
  pair<int, int> res = solver.solve(n, l, r);
  cout << res.first << " " << res.second << endl;
  return 0;
}