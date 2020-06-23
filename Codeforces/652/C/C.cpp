#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
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
  vector<ll> arr;
  readArray(arr, n);
  vector<ll> cnt;
  readArray(cnt, k);
  sort(arr.begin(), arr.end());
  sort(cnt.begin(), cnt.end());
  ll ans = 0;
  int j = n - 1;
  for (int i = 0; i < k; ++i) {
    --cnt[i];
    // cout << arr[j] << " ";
    if (cnt[i] == 0) {
      ans += 2 * arr[j--];
    } else {
      ans += arr[j--];
    }
  }
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  int i = 0;
  j = 0;
  while (i < n - k) {
    ans += arr[i];
    // cout << arr[i] << " ";
    i += cnt[j++];
  }
  // cout << endl;
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