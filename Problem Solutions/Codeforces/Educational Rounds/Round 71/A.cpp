#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
  FAST_IO;
  int t;
  cin >> t;

  int b, p, f, h, c;
  for (int i = 0; i < t; ++i) {
    cin >> b >> p >> f;
    cin >> h >> c;

    int res = 0;
    if (c > h) {
      int poss = min(b/2, f);
      res += c * poss;
      b -= 2*poss;

      res += h * min(b/2, p);
    } else {
      int poss = min(b/2, p);
      res += h * poss;
      b -= 2*poss;

      res += c * min(b/2, f);
    }
    cout << res << endl;
  }

  return 0;
}