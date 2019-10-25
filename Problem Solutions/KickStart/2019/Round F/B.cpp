#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve(int caseNo) {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = -1;
  for (int i = 0; i < 128; ++i) {
    int res = 0;
    for (int j = 0; j < n; ++j) {
      res += (a[j] ^ i);
    }
    if (res <= m) {
      ans = i;
    }
  }
  cout << "Case #" << caseNo << ": " << ans << endl;
}

int main() {
  FAST_IO;
  ll t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}