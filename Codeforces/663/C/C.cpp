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
// #define MULTIPLE_TESTS 1

const ll MOD = 1000000007;
const ll MAX = 1e6 + 10;
void solve() {
  ll n;
  cin >> n;

  vector<ll> dp(MAX, 0);
  vector<ll> fact(MAX, 1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = ((1ll * i) * fact[i - 1]) % MOD;
  }
  dp[2] = 0;
  for (int i = 3; i <= n; ++i) {
    dp[i] += (fact[i - 1] * (i - 2)) % MOD;
    dp[i] %= MOD;
    dp[i] += (2ll * dp[i - 1]) % MOD;
    dp[i] %= MOD;
  }
  cout << dp[n] << endl;
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