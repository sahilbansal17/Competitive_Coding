#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main(){
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int res = 0;
    int n, q, l, r;
    cin >> n >> q;

    string s;
    cin >> s;

    // precompute the prefix sum of frequencies for every character
    int cnt[26][n + 1];
    memset(cnt, 0, sizeof(cnt));

    ++cnt[s[0] - 'A'][1];
    for (int j = 1; j < n; ++j) {
      for (int k = 0; k < 26; ++k) {
        cnt[k][j + 1] = cnt[k][j];
      }
      ++cnt[s[j] - 'A'][j + 1];
    }

    while (q --) {
      cin >> l >> r;

      int cntOdd = 0;
      for (int k = 0; k < 26; ++k) {
        // frequency of current character
        int currentCnt = cnt[k][r] - cnt[k][l - 1];
        if (currentCnt & 1) {
          ++cntOdd;
        }
      }

      int len = (r - l + 1);
      // if length is odd, exactly one character should have odd freq
      if ((len & 1) && cntOdd == 1) {
        ++res;
      } else if (!(len & 1) && cntOdd == 0) {
        // if length is even, no character should have odd frequency
        ++res;
      }
    }
    cout << "Case #" << i << ": " << res << endl;
  }  

  return 0;
}
