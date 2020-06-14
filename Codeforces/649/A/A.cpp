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
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr;
  readArray(arr, n);
  int cur = 0;
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    cur += arr[i];
    if (cur % x != 0) {
      ans = max(ans, i + 1);
    }
  }
  cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur += arr[i];
    if (cur % x != 0) {
      ans = max(ans, n - i);
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