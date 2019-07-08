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
  void solve(int n, const vector<ll> &s, int q, const vector<pair <int, int>> &queries) {
      vector<ll> pre(n, 0);
      pre[0] = s[0];
      for (int i = 1; i < n; i ++) {
        pre[i] = pre[i - 1] + s[i];
      }

      int l, r;
      ll sum;
      for (int i = 0; i < q; i ++) {
        l = queries[i].first;
        r = queries[i].second;
        l --;
        r --;
        if (l >= 1) {
          sum = pre[r] - pre[l - 1];
        } else {
          sum = pre[r];
        }
        cout << sum/10 << endl;
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

  vector<ll> s(n);
  for (int i = 0; i < n; i ++) {
    cin >> s[i];
  }

  int q;
  cin >> q;

  vector<pair<int, int>> queries;
  int l, r;
  for (int i = 0; i < q; i ++) {
    cin >> l >> r;
    queries.push_back({l, r});
  }

  solver.solve(n, s, q, queries);

  return 0;
}