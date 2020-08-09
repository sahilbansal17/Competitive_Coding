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
  vector<ll> arr;
  readArray(arr, n);
  arr.resize(2 * n);
  // printArray(arr);
  for (int i = n; i < 2 * n; ++i) {
    arr[i] = arr[i - n];
  }
  // printArray(arr);
  ll ans = 0;
  int left = 0;
  ll cur = 0;
  while (left < n) {
    cur += arr[left];
    left += 2;
  }
  int right = left;
  left = 0;
  ans = max(ans, cur);
  while (right < 2 * n) {
    cur += arr[right];
    cur -= arr[left];
    left += 2;
    right += 2;
    ans = max(ans, cur);
  }

  left = 1;
  cur = 0;
  while (left <= n) {
    cur += arr[left];
    left += 2;
  }
  right = left;
  left = 1;
  ans = max(ans, cur);
  while (right < 2 * n) {
    cur += arr[right];
    cur -= arr[left];
    left += 2;
    right += 2;
    ans = max(ans, cur);
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