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

template <typename Container>
inline void sortContainer(Container& container) {
  sort(container.begin(), container.end());
}

void solve() {
  int n;
  cin >> n;

  vector<int> a;
  readArray(a, n);

  sortContainer(a);

  if (a[0] == a[n - 1]) {
    cout << n/2 << endl;
    return;
  }

  ll ans = 0;
  int l = 0, r = 0;
  while (l < n) {
    while (r + 1 < n && a[r + 1] == a[l]) {
      ++r;
    }
    ++r;
    // cout << r << " ";
    ans = max(ans, 1ll * (n - r) * r);
    l = r;
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