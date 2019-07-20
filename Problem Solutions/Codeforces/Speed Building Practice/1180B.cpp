#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  vector<int> solve(int n, vector<int> a) {
    for (int i = 0; i < n; ++i) {
      if (a[i] >= 0) {
        a[i] = -1*a[i] - 1;
      }
    }
    if (n & 1) {
      vector<pair<int, int> > aWithIdx;
      for (int i = 0; i < n; ++i) {
        aWithIdx.push_back({a[i], i});
      }
      sort(aWithIdx.begin(), aWithIdx.end());
      // descending order
      // reverse(aWithIdx.begin(), aWithIdx.end());
      int idx = 0;
      while (idx < n && aWithIdx[idx].first == -1) {
        idx ++;
      }
      if (idx != n) {
        a[aWithIdx[idx].second] = -1*aWithIdx[idx].first - 1;
      } else {
        a[0] = 0;
      }
    }
    return a;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  vector<int> res = solver.solve(n, a);
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  return 0;
}