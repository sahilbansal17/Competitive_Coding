#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(ll n, ll k) {
    ll cnt = 0;
    if (k > n) {
      return n;
    }
    while (n != 0) {
      if (n % k == 0) {
        n /= k;
        ++cnt;
      } else {
        ll rem = n % k;
        n -= rem;
        cnt += rem;
      }
    }
    return cnt;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  Solution solver;
  int t;
  cin >> t;

  ll n, k;
  for (int i = 0; i < t; ++i) {
    cin >> n >> k;
    cout << solver.solve(n, k) << endl;
  } 
  return 0;
}