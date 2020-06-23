#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
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
  map<ll, ll> cnt;
  ll x;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++cnt[x];
    sum += x;
  }
  int q;
  cin >> q;
  ll b, c;
  for (int i = 0; i < q; ++i) {
    cin >> b >> c;
    sum -= b * cnt[b];
    sum -= c * cnt[c];
    cnt[c] += cnt[b];
    cnt[b] = 0;
    sum += c * cnt[c];
    cout << sum << endl;
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