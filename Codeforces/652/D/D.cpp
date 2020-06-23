#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
#define MULTIPLE_TESTS 1

const int MAXN = 2e6 + 10;
const ll MOD = 1e9 + 7;
vector<ll> nodes(MAXN, 0);
vector<ll> ans(MAXN, 0);

void pre() {
  ans[0] = 0;
  ans[1] = 0;
  ans[2] = 0;
  ans[3] = 4;
  ans[4] = 4;
  ans[5] = 12;
  nodes[4] = 1;
  nodes[5] = 3;
  for (int i = 6; i <= MAXN; ++i) {
    nodes[i] = ((2 * nodes[i - 2]) % MOD + nodes[i - 1]) % MOD;
    ans[i] = (ans[i - 3] + (nodes[i] * 4) % MOD) % MOD;
  }
}
void solve() {
  // cout << ans[6] << endl;
  // cout << ans[7] << endl;
  // cout << ans[100] << endl;
  // cout << ans[2000000] << endl;
  int n;
  cin >> n;
  cout << ans[n] << endl;
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  pre();
  while (t--) {
    solve();
  }

  return 0;
}