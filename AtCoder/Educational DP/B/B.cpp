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

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> h;
  readArray(h, n);
  vector<int> cost(n);
  cost[n - 1] = 0;
  cost[n - 2] = abs(h[n - 1] - h[n - 2]);
  for (int i = n - 3; i >= 0; --i) {
    cost[i] = cost[i + 1] + abs(h[i + 1] - h[i]);
    for (int j = i + 1; j <= min(n - 1, i + k); ++j) {
      cost[i] = min(cost[i], cost[j] + abs(h[i] - h[j]));
    }
  }
  cout << cost[0] << endl;
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