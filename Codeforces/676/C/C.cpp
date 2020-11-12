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
  string s;
  cin >> s;

  int n = s.length();

  int x = 2*n - 2;
  cout << 4 << endl;
  cout << "R " << 2 << endl;
  cout << "R " << 2 << endl;
  cout << "L " << x << endl;
  cout << "L " << x - 1 << endl;
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