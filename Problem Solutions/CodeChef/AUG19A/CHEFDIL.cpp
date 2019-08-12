/*
 * https://www.codechef.com/AUG19A/problems/CHEFDIL
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  bool solve(string s) {
    int n = s.length();
    int cntOne = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++cntOne;
      }
    }
    return (cntOne & 1);
  }
};

int main() {
  FAST_IO;  
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    string s;
    cin >> s;

    Solution solver;
    if (solver.solve(s)) {
      cout << "WIN" << endl;
    } else {
      cout << "LOSE" << endl;
    }
  }
  return 0;
}