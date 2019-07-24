#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  int myLowerBound(ll val, int begin, vector<ll> &a) {
    int low = begin;
    int high = a.size() - 1;
    int mid;
    while (low < high) {
      mid = (low + (high - low)/2);
      if (a[mid] >= val) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    if (a[high] >= val) {
      return high;
    }
    return a.size();
  }
 public:
  ll solve(int n, int k, vector<ll> a) {
    ll res = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
      int idx = myLowerBound(a[i] + k, i + 1, a);
      res += (n - idx);
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n, k;
  cin >> n >> k;

  vector<ll>a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  cout << solver.solve(n, k, a) << endl;
  return 0;
}