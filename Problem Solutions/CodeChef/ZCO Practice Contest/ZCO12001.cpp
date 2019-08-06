#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  vector<int> solve(int n, vector<int> a) {
    vector<int> res; // [depth, pos, max symbols between 2, pos]
    int maxDepth = 1; // a[0] will always be 1
    int maxSymbols = 0;
    int maxDepthPos = 0; // a[0] will always be 1
    int maxSymbolsPos = -1;
    int currDepth;
    int currSymbols;
    int leftPos = 0;
    int numOpen = 1; // a[0] will always be 1
    for (int i = 1; i < n; ++i) {
      if (a[i] == 2) {
        --numOpen;
        if (numOpen == 0) {
          // a[leftPos] balanced by a[i]
          currSymbols = i - leftPos + 1;
          if (currSymbols > maxSymbols) {
            maxSymbols = currSymbols;
            maxSymbolsPos = leftPos;
          }
          leftPos = i + 1;
        }
      } else {
        ++numOpen;
        if (numOpen > maxDepth) {
          maxDepth = numOpen;
          maxDepthPos = i; // max depth position is the opening bracket at this depth
        }
      }
    }
    res.insert(res.end(), {maxDepth, maxDepthPos + 1, maxSymbols, maxSymbolsPos + 1});
    return res;
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Solution solver;
  vector<int> res = solver.solve(n, a);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}