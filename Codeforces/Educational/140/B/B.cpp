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

template <typename T>
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  if (n == 0) {
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a;

  readArray(a, n);
  int res = a[0];
  a.erase(a.begin());

  sort(a.begin(), a.end());
  // printArray(a);
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > res) {
      if ((a[i] + res) % 2 == 0) {
        res = (a[i] + res) / 2;
      } else {
        res = (a[i] + res + 1) / 2;
      }
    }
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