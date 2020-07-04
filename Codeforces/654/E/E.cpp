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
  if (n == 0) {
    cout << endl;
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}

const int MAXI = 2e4;
void solve() {
  ll n;
  ll p;
  cin >> n >> p;

  vector<ll> arr;
  readArray(arr, n);

  sort(arr.begin(), arr.end());

  vector<ll> cnt(MAXI, 0);
  for (int i = 0; i < n; ++i) {
    ++cnt[arr[i]];
  }
  for (int i = 1; i < MAXI; ++i) {
    cnt[i] = cnt[i - 1] + cnt[i];
  }
  ll mn = arr[0];
  ll mx = arr[n - 1];

  vector<ll> pos(n);
  iota(pos.begin(), pos.end(), mn);

  ll ans = 0;
  vector<int> x_arr;
  for (int i = mn; i < mx; ++i) {
    ll v = 1;
    iota(pos.begin(), pos.end(), i);
    for (int j = 0; j < n; ++j) {
      v *= (cnt[pos[j]] - j);
      v %= p;
    }
    if (v != 0) {
      ++ans;
      x_arr.push_back(i);
    }
  }
  cout << ans << endl;
  printArray(x_arr);
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