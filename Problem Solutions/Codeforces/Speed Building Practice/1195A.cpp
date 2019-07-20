#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int k, vector<int> count) {
    int res = 0;
    int oddCount = 0;
    for (int i = 1; i <= k; ++i) {
      if (count[i] % 2 == 0) {
        res += count[i];
      } else {
        res += count[i] - 1;
        ++oddCount;
      }
    }
    res += oddCount/2;
    if (oddCount & 1) {
      res += 1;
    }
    return res;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  int n, k;
  cin >> n >> k;

  vector<int> count(k + 1, 0);
  int type;
  for (int i = 0; i < n; ++i) {
    cin >> type;
    ++count[type];
  }

  Solution solver;
  cout << solver.solve(n, k, count);
  return 0;
}