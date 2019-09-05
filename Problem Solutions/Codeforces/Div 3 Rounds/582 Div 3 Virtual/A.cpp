#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
  FAST_IO;
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int res = n;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      int diff = a[i] - a[j];
      if (diff & 1) {
        ++cnt;
      }
    }
    res = min(res, cnt);
  }
  cout << res << endl;
  return 0;
}