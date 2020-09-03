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
  int n;
  cin >> n;
  vector<int> cnt(26, 0);
  string s;
  int m;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    m = s.length();
    for (int j = 0; j < m; ++j) {
      ++cnt[s[j] - 'a'];
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] % n != 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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