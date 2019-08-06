#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  bool prime(int n) {
    if (n < 2) {
      return 0;
    }
    for (int i = 2; i*i <= n; ++i) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }
 public:
  void solve(int n) {
    int m = n; // no. of edges
    while (!prime(m)) {
      ++m;
    }
    cout << m << endl;
    cout << "1 " << n << endl; // first edge
    for (int i = 0; i < n - 1; ++i) {
      cout << i + 1 << " " << i + 2 << endl;
    }
    // n edges done
    for (int i = 0; i < m - n; ++i) {
      cout << i + 1 << " " << i + 1 + n/2 << endl;
    }
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;
  Solution solver;
  solver.solve(n);
  return 0;
}