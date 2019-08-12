/*
 * https://www.codechef.com/AUG19A/problems/DSTAPLS
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  bool solve(ll n, ll k) {
    ll iterations = n/k;
    return (iterations % k);
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    ll n, k;
    cin >> n >> k;
    Solution solver;
    if (solver.solve(n, k)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}