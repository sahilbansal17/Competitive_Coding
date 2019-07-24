#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve (int n, int d, vector<int> t) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += t[i];
    }
    int totalTime = sum + 10*(n - 1);
    if (totalTime > d) {
      return -1;
    } else {
      // cerr << (d - totalTime + 10*(n - 1)) << endl;
      return (d - totalTime + 10*(n - 1))/5 ;
    }
  }
};

int main() {

  FAST_IO;
  Solution solver;
  
  int n, d;
  cin >> n >> d;

  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  cout << solver.solve(n, d, t);
  return 0;
}