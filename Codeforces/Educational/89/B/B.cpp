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

bool overlap(int a, int b, int x, int y) { return max(a, x) <= min(b, y); }
void solve() {
  ll n, x;
  cin >> n >> x;
  int m;
  cin >> m;
  ll l, r;
  ll left = x, right = x;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    if (overlap(l, r, left, right)) {
      left = min(left, l);
      right = max(right, r);
    }
  }
  ll ans = right - left + 1;
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