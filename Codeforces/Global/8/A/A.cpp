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
  ll a, b, n;
  cin >> a >> b >> n;

  ll maxi = max(a, b);
  ll res = 0;
  while (maxi <= n) {
    if (a < b) {
      a += b;
    } else {
      b += a;
    }
    maxi = max(a, b);
    ++res;
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