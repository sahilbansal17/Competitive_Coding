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

  if (n % 2 == 0) {
    cout << n / 2 << " " << n / 2 << endl;
    return;
  }
  int mx = sqrt(n);
  for (int i = 2; i <= mx; ++i) {
    if (n == i) {
      cout << 1 << " " << i - 1 << endl;
      return;
    } else if (n % i == 0) {
      cout << (n / i) << " " << (n - n / i) << endl;
      return;
    }
  }
  cout << 1 << " " << n - 1 << endl;
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