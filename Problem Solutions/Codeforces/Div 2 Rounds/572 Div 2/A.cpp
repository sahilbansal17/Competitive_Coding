/*
 * Codeforces 572 Div 2
 * Competitive Coding repository: https://github.com/sahilbansal17/Competitive_Coding
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  void solve(int n, string &s) {
    int cnt[2] = {0};
    for (int i = 0; i < n; i ++) {
      if (s[i] == '0') {
        cnt[0] ++;
      } else {
        cnt[1] ++;
      }
    }
    if (cnt[0] != cnt[1]) {
      cout << "1" << endl;
      cout << s << endl;
    } else {
      cout << "2" << endl;
      cout << s[0] << " ";
      cout << s.substr(1, n - 1) << endl;
    }
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  Solution solver;
  
  int n;
  cin >> n;

  string s;
  cin >> s;
  solver.solve(n, s);

  return 0;
}