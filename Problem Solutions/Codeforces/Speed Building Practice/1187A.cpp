#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, int s, int t) {
    int common = s + t - n;
    int res = max(s - common, t - common) + 1;
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

  int T;
  cin >> T;
  int n, s, t;

  Solution solver;
  for (int i = 0; i < T; ++i) {
    cin >> n >> s >> t;
    cout << solver.solve(n, s, t) << endl;
  }
  return 0;
}