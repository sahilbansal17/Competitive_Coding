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
template <typename T>
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> ans(n, 0);
  int cnt = 0;
  char prev = s[0];
  ans[0] = 1;
  ++cnt;
  set<int> ended_at[2];
  if (prev == '0') {
    ended_at[0].insert(cnt);
  } else {
    ended_at[1].insert(cnt);
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0' && ended_at[1].size() >= 1) {
      ans[i] = *(ended_at[1].begin());
      ended_at[0].insert(ans[i]);
      ended_at[1].erase(ans[i]);
    } else if (s[i] == '1' && ended_at[0].size() >= 1) {
      ans[i] = *(ended_at[0].begin());
      ended_at[1].insert(ans[i]);
      ended_at[0].erase(ans[i]);
    } else {
      ++cnt;
      ans[i] = cnt;
      if (s[i] == '0') {
        ended_at[0].insert(cnt);
      } else {
        ended_at[1].insert(cnt);
      }
    }
  }
  cout << cnt << endl;
  printArray(ans);
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