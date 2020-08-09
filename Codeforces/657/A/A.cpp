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

string t = "abacaba";
int count_healthy(string& s) {
  int n = s.length();
  int cnt = 0;
  for (int i = 0; i < n - 6; ++i) {
    bool found = true;
    for (int j = i; j <= i + 6; ++j) {
      if (s[j] != t[j - i]) {
        found = false;
      }
    }
    if (found) {
      ++cnt;
    }
  }
  return cnt;
}
void replace_all_by_z(string& s) {
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      s[i] = 'z';
    }
  }
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt = count_healthy(s);
  if (cnt > 1) {
    cout << "NO" << endl;
    return;
  }
  if (cnt == 1) {
    cout << "YES" << endl;
    // replace all ? with z
    replace_all_by_z(s);
    cout << s << endl;
    return;
  }
  // cnt == 0, try replacing all except in single window by z and counting
  string temp = s;
  replace_all_by_z(temp);

  // consider window size of 7, replace and count
  for (int i = 0; i < n - 6; ++i) {
    string temp_temp = temp;
    for (int j = i; j < i + 7; ++j) {
      if (s[j] != t[j - i]) {
        if (s[j] != '?') {
          break;
        } else {
          temp_temp[j] = t[j - i];
        }
      }
    }
    // cout << temp_temp << endl;
    if (count_healthy(temp_temp) == 1) {
      cout << "YES" << endl;
      cout << temp_temp << endl;
      return;
    }
  }
  cnt = 0;

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