/*
 * Problem Link: https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/maximum-sum-4-f8d12458/
 */

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main() {
  int n;
  cin >> n;

  vector<int> a(n);

  ll res = 0;
  int count = 0;

  int maxi = INT_MIN;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= 0) {
      res += 1ll * a[i];
      ++count;
    }
    if (a[i] > maxi) {
      maxi = a[i];
    }
  }
  if (count == 0) {
    cout << maxi << " " << 1 << endl;
    return 0;
  }
  cout << res << " " << count << endl;

  return 0;
}
