#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
int main() {
  FAST_IO;
  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  int t;
  cin >> t;

  for (int k = 0; k < t; ++k) {
    string x, y;
    cin >> x >> y;

    int n = x.length();
    int m = y.length();

    // match the rightmost 1 in y with rightmost possible 1 in x
    int j = m - 1;
    int posY = -1;
    while (j >= 0) {
      if (y[j] == '1') {
        posY = j;
        break;
      }
      --j;
    }

    int i = n - 1 - (m - 1 - posY);
    int res = 0;
    while (i >= 0) {
      if (x[i] == '1') {
        break;
      }
      --i;
      ++res;
    }
    cout << res << endl;
  }
  return 0;
}