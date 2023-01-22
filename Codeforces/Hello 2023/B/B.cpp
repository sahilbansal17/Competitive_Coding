#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

void solve() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  if (n % 2 == 0) {
    for (int i = 0; i < n; ++i) {
      if (i & 1) { cout << -1 << " "; }
      else { cout << 1 << " "; }
    }
  } else {
    // k - 1, -k
    int k = (n - 1) / 2;
    for (int i = 0; i < n - 1; ++i) {
      if (i & 1) { cout << -1*k << " "; }
      else { cout << k - 1 << " "; }
    }
    cout << k - 1 << " ";
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