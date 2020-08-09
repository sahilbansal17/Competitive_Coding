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
void solve() {
  int n;
  cin >> n;
  vector<int> weight;
  readArray(weight, n);

  int res = 0;
  vector<int> cnt;
  int addition;
  for (int sum = 2; sum <= 100; ++sum) {
    // count max pairs with given sum
    cnt.assign(101, 0);
    for (int i = 0; i < n; ++i) {
      ++cnt[weight[i]];
    }
    int cur = 0;
    for (int i = 0; i < 51; ++i) {
      if (sum - i <= 0) {
        continue;
      }
      if (i != sum - i && cnt[i] >= 1 && cnt[sum - i] >= 1) {
        addition = min((int)cnt[i], (int)cnt[sum - i]);
        cnt[sum - i] -= addition;
        cnt[i] -= addition;
        cur += addition;
      } else if (i == sum - i && cnt[i] >= 2) {
        addition = (cnt[i]) / 2;
        cnt[i] -= 2*addition;
        cur += addition;
      }
    }
    res = max(res, cur);
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