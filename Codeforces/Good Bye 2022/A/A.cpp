#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
 
// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1
 
template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}
 
void solve() {
  int n, m;
  cin >> n >> m;
 
  vector<ll> a(n), b(m);
  readArray(a, n);
  readArray(b, m);
 
  ll ans = b[m - 1];

  vector<ll> c(n + m - 1);
  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
  }
  for (int i = 0; i < m - 1; ++i) {
    c[i + n] = b[i];
  }

  sort(c.begin(), c.end(), greater<ll>());

  for (int i = 0; i < n - 1; ++i) {
    ans += c[i];
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