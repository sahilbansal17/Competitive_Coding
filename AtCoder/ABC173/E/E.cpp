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

const ll MOD = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  ll ans = 1;
  if (arr[n - 1] == 0 && (k & 1)) {
    cout << 0 << endl;
    return;
  }

  if (arr[n - 1] <= 0 && (k & 1)) {
    for (int i = n - 1; i >= n - k; --i) {
      ans *= abs(arr[i]);
      ans %= MOD;
    }
    cout << (MOD - ans + MOD) % MOD << endl;
    return;
  }

  int i = 0, j = n - 1;
  if (k & 1) {
    ans *= arr[j];
    ans %= MOD;
    --j;
    --k;
  }

  k >>= 1;
  for (int p = 0; p < k; ++p) {
    ll left = (arr[i] * arr[i + 1]);
    ll right = (arr[j] * arr[j - 1]);
    bool take_care = false;
    if (left > right) {
      if (left < 0) {
        take_care = true;
      }
      ans *= (abs(left) % MOD);
      ans %= MOD;
      i += 2;
    } else {
      if (right < 0) {
        take_care = true;
      }
      ans *= (abs(right) % MOD);
      ans %= MOD;
      j -= 2;
    }
    if (take_care) {
      ans = (MOD - ans + MOD) % MOD;
    }
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