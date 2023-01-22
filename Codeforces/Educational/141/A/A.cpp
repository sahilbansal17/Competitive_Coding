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

  vector<int> a;
  readArray(a, n);

  if (a[0] == a[n - 1]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << a[n - 1] << " ";
    for (int i = 0; i < n - 1; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
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