#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MAX = 100010LL;

void solve(int caseNo) {
  int ans = 0;
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> cnt(MAX, 0);
  int x;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    for (int j = 1; j <= sqrt(x); ++j) {
      if (x % j == 0) {
        ++cnt[j];
        if (j != sqrt(x)) {
          ++cnt[x/j];
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < q; ++i) {
    cin >> x;
    ans = n/x;
    ans -= cnt[x];
    res += ans;
  }
  cout << "Case #" << caseNo << ": " << res << endl;
}

int main() {
  FAST_IO;
  ll t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}