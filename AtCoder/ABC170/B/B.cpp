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
  int x, y;
  cin >> x >> y;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      if (2 * i + 4 * j == y && i + j == x) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
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