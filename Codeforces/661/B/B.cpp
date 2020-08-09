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

template <typename T>
inline T sumArray(const vector<T>& arr) {
  T sum = accumulate(arr.begin(), arr.end(), 0);
  return sum;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> candies, oranges;
  readArray(candies, n);
  readArray(oranges, n);

  ll x = *min_element(candies.begin(), candies.end());
  ll y = *min_element(oranges.begin(), oranges.end());

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += max(candies[i] - x, oranges[i] - y);
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