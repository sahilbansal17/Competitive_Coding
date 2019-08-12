/*
 * https://www.codechef.com/AUG19A/problems/ENCODING
 * Subtask 1
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 1000000007;
class Solution {
 public:
  ll solve(int nl, string l, int nr, string r) {
    ll left = stoll(l);
    ll right = stoll(r);

    ll res = 0;
    while (left <= right) {
      ll cur = left;
      string s = to_string(cur);
      int n = s.length();
      int i = 0;
      while (i < n) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) {
          s[j] = '0';
          ++j;
        }
        i = j;
      }
      ++left;
      res += stoll(s);
      res %= MOD;
    }
    return res;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int nl;
    string l;
    cin >> nl >> l;

    int nr;
    string r;
    cin >> nr >> r;

    Solution solver;
    cout << solver.solve(nl, l, nr, r) << endl;
  }
  
  return 0;
}