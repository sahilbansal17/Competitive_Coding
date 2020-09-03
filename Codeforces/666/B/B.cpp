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

ll cost(ll mid, vector<ll>& arr) {
  int n = arr.size();
  ll cur = 1;
  ll curCost = 0;
  bool dontConsider = false;
  for (int j = 0; j < n; ++j) {
    curCost += abs(arr[j] - cur);
    if (cur > (1e18/mid)) {
      dontConsider = true;
      break;
    }
    cur *= mid;
  }
  if (dontConsider) {
    return 1e18;
  }
  return curCost;
}

void solve() {
  int n;
  cin >> n;

  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  ll low = 1, high = 1e9;
  ll mid;
  while (low < high) {
    mid = low + (high - low)/2;
    ll c1 = cost(mid, arr);
    if (c1 == 1e18) {
      high = mid;
      continue;
    }
    ll c2 = cost(mid + 1, arr);
    if (c2 > c1) {
      high = mid;
    } else {
      low = mid + 1;
    }
    // cout << mid << " " << c1 << " " << c2 << endl;
  }
  cout << cost(low, arr) << endl;
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