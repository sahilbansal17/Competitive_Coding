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
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  readArray(arr, n);

  vector<int> ans;
  vector<int> marked(n + 1, 0);
  for (int i = 0; i < 2 * n; ++i) {
    bool sorted = true;
    for (int j = 1; j < n; ++j) {
      if (arr[j] < arr[j - 1]) {
        sorted = false;
        break;
      }
    }
    if (sorted) {
      break;
    }
    vector<int> done(n + 1, 0);
    for (int j = 0; j < n; ++j) {
      ++done[arr[j]];
    }
    int mex = 0;
    for (int j = 0; j <= n; ++j) {
      if (done[j] == 0) {
        mex = j;
        break;
      }
    }
    int tmp;
    if (mex == n) {
      tmp = mex - 1;
    } else {
      tmp = mex;
    }
    if (ans.size() >= n) {
      arr[tmp] = mex;
      ans.push_back(tmp + 1);
    } else {
      for (int j = tmp; j >= 0; --j) {
        if (j <= mex && !marked[j]) {
          arr[j] = mex;
          ans.push_back(j + 1);
          marked[j] = 1;
          break;
        }
      }
    }
  }

  cout << ans.size() << endl;
  printArray(ans);
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