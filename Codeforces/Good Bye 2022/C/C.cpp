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
  int n;
  cin >> n;

  vector<ll> arr;
  readArray(arr, n);

  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      cout << "NO" << endl;
      return;
    }
  }

  vector<int> cnt(n/2 + 1, 0);
  for (int mod = 2; mod <= n/2; ++mod) {
    for (int i = 0; i < mod; ++i) {
      cnt[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
      cnt[arr[i] % mod]++;
    }

    int mn = cnt[0];
    for (int i = 0; i < mod; ++i) {
      if (cnt[i] < mn) {
        mn = cnt[i];
      }
    }
    if (mn >= 2) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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