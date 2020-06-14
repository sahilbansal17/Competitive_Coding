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
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  vector<int> done(102, 0);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    done[p[i]] = 1;
  }
  int left, right;
  for (int k = x; k >= 0; --k) {
    if (!done[k]) {
      left = k;
      break;
    }
  }
  for (int k = x + 1; k < 102; ++k) {
    if (!done[k]) {
      right = k;
      break;
    }
  }
  if (x - left <= right - x) {
    cout << left << endl;
  } else {
    cout << right << endl;
  }
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