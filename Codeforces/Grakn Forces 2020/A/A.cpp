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
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a, b, c, p;
  readArray(a, n);
  readArray(b, n);
  readArray(c, n);
  
  p.resize(n);
  p[0] = a[0];
  for (int i = 1; i < n - 1; ++i) {
    if (a[i] != p[i - 1]) {
      p[i] = a[i];
      continue;
    }
    if (b[i] != p[i - 1]) {
      p[i] = b[i];
      continue;
    }
    p[i] = c[i];
  }
  if (a[n - 1] != p[n - 2] && a[n - 1] != p[0]) {
    p[n - 1] = a[n - 1];
  }else if (b[n - 1] != p[n - 2] && b[n - 1] != p[0]) {
    p[n - 1] = b[n - 1];
  } else {
    p[n - 1] = c[n - 1];
  }
  printArray(p);
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