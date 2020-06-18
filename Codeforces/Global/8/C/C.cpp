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
  int n;
  cin >> n;

  int cnt = 7 + (n - 1) * 3;
  cout << cnt << endl;
  cout << 0 << " " << 0 << endl;
  cout << 0 << " " << 1 << endl;
  cout << 1 << " " << 0 << endl;
  cout << 1 << " " << 1 << endl;
  cout << 2 << " " << 1 << endl;
  cout << 2 << " " << 2 << endl;
  cout << 1 << " " << 2 << endl;
  --n;
  int x = 2, y = 2;
  while (n) {
    cout << x << " " << y + 1 << endl;
    cout << (x + 1) << " " << y << endl;
    cout << (x + 1) << " " << (y + 1) << endl;
    --n;
    ++x;
    ++y;
  }
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