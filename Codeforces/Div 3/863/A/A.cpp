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
  int n, d;
  cin >> n >> d;

  string s;
  cin >> s;

  bool inserted = false;
  for (int i = 0; i < n; ++i) {
    if ((s[i] - '0') < d) {
      // insert d at i
      s.insert(i, 1, d + '0');
      inserted = true;
      break;
    }
  }

  if (!inserted) {
    s += d + '0';
  }

  cout << s << endl;
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