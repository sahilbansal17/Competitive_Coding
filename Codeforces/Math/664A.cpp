#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
// #define MULTIPLE_TESTS 1

void solve() {
  string a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a << endl;
  } else {
    cout << 1 << endl;
  }
  return;
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