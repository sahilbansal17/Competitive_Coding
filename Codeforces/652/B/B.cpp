#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
#define MULTIPLE_TESTS 1

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  bool seen_one = false;
  int last_zero = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      last_zero = i;
      break;
    }
  }
  if (last_zero == -1) {
    cout << s << endl;
    return;
  }
  for (int i = 0; i < last_zero; ++i) {
    if (s[i] == '1') {
      seen_one = true;
    }
  }
  if (seen_one == false) {
    cout << s << endl;
    return;
  }
  for (int i = 0; i < last_zero; ++i) {
    if (s[i] == '0') {
      cout << '0';
    } else {
      break;
    }
  }
  cout << '0';
  cout << s.substr(last_zero + 1) << endl;
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