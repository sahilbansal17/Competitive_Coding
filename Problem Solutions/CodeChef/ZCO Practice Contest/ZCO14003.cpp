#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(int n, vector<ll> a) {
    ll res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      res = max(res, a[i]*(n - i));
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;

  vector<ll>a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, a) << endl;
  return 0;
}