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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return (a * b)/gcd(a, b);
}
void solve() {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << -1*arr[0] << endl;
    for (int i = 0; i < 2; ++i) {
      cout << 1 << " " << 1 << endl;
      cout << 0 << endl;
    }
    return;
  }
  cout << 1 << " " << n - 1 << endl;
  for (int i = 0; i < n - 1; ++i) {
    // ll to_make = lcm(abs(arr[i]), n);
    ll to_make = arr[i] * n;
    cout << to_make - arr[i] << " ";
    arr[i] = to_make;
  }
  cout << endl;

  cout << 1 << " " << n << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << -1*arr[i] << " ";
  }
  cout << 0;
  cout << endl;

  cout << n << " " << n << endl;
  cout << -1*arr[n - 1] << endl;
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