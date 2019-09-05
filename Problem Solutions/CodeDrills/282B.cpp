/*
 * Code Drills recommendation:
 * https://code-drills.com/recommendations/491fc07f-8605-42a2-8a2a-8c2b33ae7add
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() {
  FAST_IO;
  int n;
  cin >> n;

  int a, g;
  int sumA = 0, sumG = 0;
  string res;
  for (int i = 0; i < n; ++i) {
    cin >> a >> g;
    if (abs(sumA + a - sumG) <= 500) {
      sumA += a;
      res += 'A';
    } else if (abs(sumG + g - sumA) <= 500) {
      sumG += g;
      res += 'G';
    } else {
      cout << "-1";
      return 0;
    }
  }
  cout << res << endl;
  return 0;
}