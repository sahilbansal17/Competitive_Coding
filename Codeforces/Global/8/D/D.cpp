#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
  ll ans = 0;
  vector<ll> cnt(21, 0);
  for (int bit = 0; bit <= 20; ++bit) {
    for (int j = 0; j < n; ++j) {
      if (arr[j] & (1 << bit)) {  // bit is set in j-th num
        ++cnt[bit];
      }
    }
  }
  while (1) {
    ll cur = 0;  // constructed number from the last
    for (int bit = 0; bit <= 20; ++bit) {
      if (cnt[bit] > 0) {  // bit available for use
        cur |= (1 << bit);
        --cnt[bit];  // used up;
      }
    }
    ans += cur * cur;  // update ans
    if (cur == 0) {
      break;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}