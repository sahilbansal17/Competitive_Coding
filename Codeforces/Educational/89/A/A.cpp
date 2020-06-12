#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
#define MULTIPLE_TESTS 1

void solve() {
  ll a, b;
  cin >> a >> b;
  ll mini = min(a, b);
  ll maxi = max(a, b);
  if (maxi >= 2 * mini) {
    cout << mini << endl;
    return;
  }
  ll ans = maxi - mini;
  ll x = mini - ans;
  ans += (x / 3) * 2;
  if (x % 3 == 2) {
    ++ans;
  }
  cout << ans << endl;
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