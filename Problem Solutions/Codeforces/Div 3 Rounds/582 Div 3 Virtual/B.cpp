#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int solve(vector<int> &a) {
  int n = a.size();
  int currentMin = a[n - 1];
  int res = 0;
  for (int j = n - 2; j >= 0; --j) {
    currentMin = min(currentMin, a[j]);
    if (currentMin != a[j]) {
      ++res;
    }
  }
  return res;
}

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }

    int res = solve(a);
    cout << res << endl;
  }
  
  return 0;
}