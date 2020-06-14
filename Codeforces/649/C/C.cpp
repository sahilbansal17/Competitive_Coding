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
// #define MULTIPLE_TESTS 1
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
  vector<int> arr;
  readArray(arr, n);
  vector<int> b(n, -1);
  vector<int> done(n + 1, 0);
  int i = 0;
  while (i < n) {
    while (i + 1 < n && arr[i + 1] == arr[i]) {
      ++i;
    }
    if (i + 1 < n) {
      b[i + 1] = arr[i];
    }
    done[arr[i]] = 1;
    ++i;
  }
  int k = 0;
  for (int i = 0; i < n; ++i) {
    while (done[k] == 1) {
      ++k;
    }
    if (b[i] == -1) {
      b[i] = k;
      ++k;
    }
  }
  printArray(b);
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