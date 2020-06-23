#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

void solve() {
  ll n;
  cin >> n;

  string ans;
  ll cur = 26;
  int len = 0;
  ll t = n;
  while (n > 0) {
    n -= cur;
    cur *= 26;
    ++len;
  }
  ll pow = 26;
  n = t;
  for (int i = 0; i < len; ++i) {
    ll cur = n % 26;
    if (cur == 0) {
      ans += 'z';
      n /= 26;
      --n;
    } else {
      ans += ('a' + cur - 1);
      n /= 26;
    }
  }
  reverse(ans.begin(), ans.end());
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