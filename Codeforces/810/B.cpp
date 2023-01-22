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
  int n, m;
  cin >> n >> m;

  vector<int> c;
  readArray(c, n);

  vector<int> adj[n], degree(n, 0);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++degree[u];
    ++degree[v];
    edges.push_back({u, v});
  }

  if (m % 2 == 0) {
    cout << 0 << endl;
    return;
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (degree[i] % 2 == 1) {
      ans = min(ans, c[i]);
    }
  }

  for (int i = 0; i < m; ++i) {
    int u = edges[i].first;
    int v = edges[i].second;
    if (degree[u] % 2 == 0 && degree[v] % 2 == 0) {
      ans = min(ans, c[u] + c[v]);
    }
  }
  cout << ans << endl;
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