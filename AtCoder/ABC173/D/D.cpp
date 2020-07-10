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
template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<ll> arr;
  readArray(arr, n);

  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  ll ans = arr[0];
  int k = 1;
  int cnt = 2;
  while (cnt < n) {
    ans += arr[k];
    ++cnt;
    if (cnt % 2 == 0) {
      ++k;
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