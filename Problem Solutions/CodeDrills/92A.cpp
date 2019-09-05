/*
 * Code Drills recommendation:
 * https://code-drills.com/recommendations/491fc07f-8605-42a2-8a2a-8c2b33ae7add
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() {
  FAST_IO;  
  int n, m;
  cin >> n >> m;

  int cur = 1;
  int done = 0;
  while (done + cur <= m) {
    done += cur;
    ++cur;
    if (cur == n + 1) {
      cur = 1;
    }
  }

  cout << m - done << endl;
  return 0;
}