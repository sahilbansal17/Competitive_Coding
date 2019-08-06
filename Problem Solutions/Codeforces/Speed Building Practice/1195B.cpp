#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int k) {
    ll D = 9 + 8ll*(n + k);
    ll x = (-3 + sqrt(D))/2;
    int res = (n - x);
    return res;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  int n, k;
  cin >> n >> k;

  Solution solver;
  cout << solver.solve(n, k) << endl;
  return 0;
}