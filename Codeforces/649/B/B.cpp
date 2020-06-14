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
  vector<int> p;
  readArray(p, n);
  vector<int> res;
  res.push_back(p[0]);
  int inc = -1;
  for (int i = 1; i < n; ++i) {
    if (p[i] > p[i - 1]) {
      if (inc == -1) {
        inc = 1;
      } else if (inc == 0) {
        res.push_back(p[i - 1]);
        inc = 1;
      }
    } else {
      if (inc == -1) {
        inc = 0;
      } else if (inc == 1) {
        res.push_back(p[i - 1]);
        inc = 0;
      }
    }
  }
  res.push_back(p[n - 1]);
  cout << res.size() << endl;
  printArray(res);
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