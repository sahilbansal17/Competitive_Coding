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
  int n, k;
  cin >> n >> k;
  vector<int> arr;
  readArray(arr, n);

  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int used = 0;
  int prev = arr[0];
  int res = 1;
  for (int i = 1; i < n; ++i) {
    if (arr[i] != prev) {
      ++used;
      if (used == k) {
        used = 1;
        ++res;
      }
    }
    prev = arr[i];
  }
  ++used;
  if (used > k && k == 1) {
    cout << -1 << endl;
    return;
  }
  cout << res << endl;
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