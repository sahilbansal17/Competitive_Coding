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
inline void withIdConstruction(vector<pair<T, T>>& with_id,
                               const vector<T>& arr) {
  for (int idx = 0; idx < arr.size(); ++idx) {
    with_id.push_back({arr[idx], idx});
  }
}

template <typename Container>
inline void sortContainer(Container& container) {
  sort(container.begin(), container.end());
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
  ll n, w;
  cin >> n >> w;
  vector<ll> weights;
  readArray(weights, n);
  vector<pair<ll, ll>> with_id;
  withIdConstruction(with_id, weights);
  sortContainer(with_id);

  ll mini = w/2;
  if (w & 1ll) {
    ++mini;
  }
  int iid = n - 1;
  for (int id = 0; id < n; ++id) {
    ll val = with_id[id].first;
    if (val > w) {
      iid = id - 1;
      break;
    }
    if (val >= mini && val <= w) {
      cout << 1 << endl;
      cout << with_id[id].second + 1 << endl;
      return;
    }
  }
  if (iid == -1) {
    cout << -1 << endl;
    return;
  }

  vector<ll> res;
  ll cur = 0;
  int id = 0;
  while (id <= iid && cur < w) {
    if (cur >= mini) {
      break;
    }
    cur += with_id[id].first;
    res.push_back(with_id[id].second + 1);
    ++id;
  }
  if (cur >= mini && cur <= w) {
    cout << res.size() << endl;
    printArray(res);
  } else {
    cout << -1 << endl;
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