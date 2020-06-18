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

void solve() {
  ll k;
  cin >> k;

  vector<int> cnt(10, 1);
  ll ans = 1;
  int cur = 0;
  while (ans < k) {
    ans /= cnt[cur];
    ++cnt[cur];
    if (ans > (1e16 / cnt[cur])) {
      break;
    }
    ans *= cnt[cur];
    ++cur;
    cur %= 10;
  }
  string s = "codeforces";
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      cout << s[i];
    }
  }
  cout << endl;
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