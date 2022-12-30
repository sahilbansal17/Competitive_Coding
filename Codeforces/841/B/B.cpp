#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1
const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;

  ll ans = 337;
  ans *= n;
  ans %= MOD;

  ans *= (n + 1);
  ans %= MOD;

  ans *= ((4*n) % MOD - 1 + MOD) % MOD;
  ans %= MOD;

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