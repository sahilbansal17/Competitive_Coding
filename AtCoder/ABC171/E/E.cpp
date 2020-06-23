#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
void solve() {
  int n;
  cin >> n;
  ll x;
  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<ll> brr(n);
  ll xori = 0;
  for (int i = 0; i < n / 2; ++i) {
    brr[i] = arr[i] ^ arr[n - i - 1];
    xori ^= brr[i];
    brr[n - i - 1] = brr[i];
  }
  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = arr[i] ^ xori ^ brr[i];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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