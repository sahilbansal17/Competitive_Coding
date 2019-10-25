#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll cnt = 0;
void rec(int i, int n, ll s1, ll s2, ll h, vector<ll> &a, vector<ll> &b) {
  if (i == n) {
    cerr << s1 << " " << s2 << endl;
    if (s1 >= h && s2 >= h) {
      ++cnt;
    }
    return ;
  }
  rec(i + 1, n, s1 + a[i], s2, h, a, b);
  rec(i + 1, n, s1, s2 + b[i], h, a, b);
  rec(i + 1, n, s1 + a[i], s2 + b[i], h, a, b);
}

void solve(int caseNo) {
  int n;
  ll h;
  cin >> n >> h;

  vector<ll> a(n), b(n);
  ll sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum1 += a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    sum2 += b[i];
  }

  int ans = 0;
  if (sum1 < h || sum2 < h) {
    ans = 0;
  } else {
    rec(0, n, 0, 0, h, a, b);
    ans = cnt;
    cnt = 0;
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