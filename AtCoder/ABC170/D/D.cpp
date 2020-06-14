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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(1e6 + 10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = a[i];
    bool possible = true;
    for (int j = 1; j <= sqrt(cur); ++j) {
      if (j == cur && cnt[j] >= 2) {
        possible = false;
        break;
      }
      if (j == 1 && cnt[cur] >= 2) {
        possible = false;
        break;
      }
      if (j != cur && cur % j == 0 && cnt[j] >= 1) {
        possible = false;
        break;
      }
      if (j != 1 && cur % (cur / j) == 0 && cnt[(cur / j)] >= 1) {
        possible = false;
        break;
      }
    }
    if (possible) {
      ++ans;
    }
  }
  cout << ans << endl;
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