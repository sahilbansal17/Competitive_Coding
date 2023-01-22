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
  string s;
  cin >> n;
  cin >> s;

  int cntL = 0, cntR= 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      ++cntR;
    } else {
      ++cntL;
    }
  }
  if (cntL == 0 || cntR == 0) {
    cout << -1 << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      cout << i + 1 << endl;
      return;
    }
  }

  cout << 0 << endl;
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