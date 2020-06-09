#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
#define MULTIPLE_TESTS 1

template <typename T>
inline void readArray(vector<T>& arr, int n);

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  readArray(arr, n);
  if (n & 1) {
    cout << -1 << endl;
    return;
  }

  vector<int> cntOrg(1025, 0);
  for (auto x : arr) {
    ++cntOrg[x];
  }
  if (n == 2 && cntOrg[0] == 1) {
    if (arr[0] != 0) {
      cout << arr[0] << endl;
    } else {
      cout << arr[1] << endl;
    }
    return;
  }
  for (int i = 1; i < (1 << 10); ++i) {
    vector<int> cnt(1025, 0);
    for (int j = 0; j < n; ++j) {
      ++cnt[arr[j] ^ i];
    }
    bool possible = true;
    for (auto x : arr) {
      if (cnt[x] != 1) {
        possible = false;
      }
    }
    if (possible) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
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

template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}