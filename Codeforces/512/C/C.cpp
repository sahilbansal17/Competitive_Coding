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

bool possible(int id, int cur, string& s, int targ) {
  if (id == s.length()) {
    return cur == targ;
  }
  int val = s[id] - '0';
  if (cur < targ) {
    return possible(id + 1, cur + val, s, targ);
  } else if (cur == targ) {
    return possible(id, 0, s, targ);
  } else if (cur > targ) {
    return false;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cur = 0;
  bool allzero = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '0') {
      allzero = false;
    }
  }
  if (allzero) {
    cout << "YES" << endl;
    return;
  }
  // remove all zeroes
  string t = "";
  for (int i = 0; i < n; ++i) {
    if (s[i] != '0') {
      t += s[i];
    }
  }
  n = t.length();
  for (int i = 0; i < n; ++i) {
    cur += (t[i] - '0');
    if (cur == 0) {
      continue;
    }
    if (possible(i + 1, 0, t, cur)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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