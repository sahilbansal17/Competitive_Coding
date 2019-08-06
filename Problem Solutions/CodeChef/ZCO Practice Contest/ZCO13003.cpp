#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  ll solve(int n, int k, vector<ll> a) {
    // sort the array and use two pointer approach
    sort(a.begin(), a.end());
    int left = 0;
    int right = n - 1;
    ll res = 0; // required no. of pairs
    while (left < right) {
      if (a[left] + a[right] < k) {
        res += (right - left); // all these pairs will contribute
        ++left; // can now increase the left pointer
      } else {
        --right; // need to decrease right pointer
      }
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, k, a);
  return 0;
}