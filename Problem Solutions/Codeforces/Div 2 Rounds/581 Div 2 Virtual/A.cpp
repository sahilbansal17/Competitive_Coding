#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(string s) {
    int n = s.length();
    int res = ceil((1.0*n)/2);
    if (n == 1) {
      return 0;
    }
    if (n & 1 && s[0] == '1') {
      bool poss = true;
      for (int i = 1; i < n; ++i) {
        if (s[i] == '1') {
          poss = false;
        }
      }
      if (poss) {
        --res;
      }
    }
    return res;
  }
};

int main() {
  FAST_IO;
  string s;
  cin >> s;

  Solution solver;
  cout << solver.solve(s);
  return 0;
}