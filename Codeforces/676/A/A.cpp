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
  int a, b;
  cin >> a >> b;

  int res = 0;
  for (int i = 31; i >= 0; --i) {
    int cur = (1 << i);
    if ((a & cur) && (b & cur)) {
      continue;
    } else if (a & cur) {
      res += cur;
    } else if (b & cur) {
      res += cur;
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