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
  int n, k;
  cin >> n >> k;

  vector<int> h, p;
  readArray(h, n);
  readArray(p, n);

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return p[i] < p[j];
  });

  int damage = 0;
  for (int i : ord) {
    // already dead
    if (h[i] <= damage) {
      continue;
    }

    // no damage before first round
    if (i != ord[0]) {
      k -= p[i];
    }

    // perform round
    if (k > 0) {
      damage += k;
      while (h[i] > damage) {
        k -= p[i];
        if (k < 0) {
          break;
        }
        damage += k;
      }
    }

    // if still alive, then no
    if (h[i] > damage) {
      cout << "NO" << endl;
      return;
    }
  }
  
  cout << "YES" << endl;
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