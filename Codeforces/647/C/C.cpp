#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
#define MULTIPLE_TESTS 1

void solve() {
  ll n;
  cin >> n;

  ll res = 0;
  for (int i = 63; i >= 0; --i) {
    if (n & (1ll << i)) {
      // cout << i << endl;
      res += (1ll << (i + 1)) - 1;
    }
  }
  cout << res << endl;
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  while (t--) {
    solve();
  }

  return 0;
}