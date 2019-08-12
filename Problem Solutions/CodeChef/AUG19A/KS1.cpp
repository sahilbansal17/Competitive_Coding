/*
 * https://www.codechef.com/AUG19A/problems/KS1
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(int n, vector<ll> a) {
    map<ll, pair<ll, ll>> cnt; // pair: {count, sum of (end + 2) values}
    ll currentXor = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      currentXor ^= a[i];
      if (cnt.find(currentXor) != cnt.end()) {
        ll currentCnt = cnt[currentXor].first;
        ll sumEnds = cnt[currentXor].second;
        // consider all triplets ending at index i
        res += (i + 1)*currentCnt - sumEnds;
        ++cnt[currentXor].first;
        cnt[currentXor].second += (i + 2);
      } else {
        cnt[currentXor] = {1, (i + 2)};
      }
      if (currentXor == 0) {
        res += i;
      }
    }
    return res;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    Solution solver;
    cout << solver.solve(n, a) << endl;
  }
  
  return 0;
}