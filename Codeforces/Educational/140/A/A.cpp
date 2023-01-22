#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;

// Uncomment the #define below if problem contains multiple test cases
#define MULTIPLE_TESTS 1

void solve() {
  unordered_set<int> x, y;
  
  int a, b;
  for (int i = 0; i < 3; ++i) {
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }

  if (x.size() == 3 || y.size() == 3) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
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