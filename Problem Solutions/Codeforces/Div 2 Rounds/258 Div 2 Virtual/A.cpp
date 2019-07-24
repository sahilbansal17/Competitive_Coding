#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  string solve(int n, int m) {
    int cnt = n*m;
    int steps = 0;
    while (cnt > 0) {
      --n;
      --m;
      cnt = n*m;
      ++steps;
    }
    if (steps & 1) {
      return "Akshat";
    }
    return "Malvika";
  }
};

int main() {

  FAST_IO;
  int n, m;
  cin >> n >> m;

  Solution solver;
  string res = solver.solve(n, m);
  cout << res << endl;
  return 0;
}