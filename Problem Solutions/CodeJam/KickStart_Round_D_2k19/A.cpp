#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  int countSetBits(int n) {
    int count = 0;
    while (n) {
      count += (n & 1);
      n >>= 1;
    }
    return count;
  }
 public:
  vector<int> solve(int n, int q, vector<int> &a,
            vector<pair<int, int>> &queries) {
    int cnt, prevCnt;
    set<int> oddSetBitSet;
    for (int i = 0; i < n; ++i) {
      cnt = countSetBits(a[i]);
      if (cnt & 1) {
        oddSetBitSet.insert(i);
      }
    }

    vector<int> res;
    int currentAns;
    for (int i = 0; i < q; ++i) {
      int p = queries[i].first;
      int v = queries[i].second;
      cnt = countSetBits(v);
      // check if previous element at this pos had odd set bits
      prevCnt = countSetBits(a[p]);
      a[p] = v;
      if (prevCnt & 1) {
        oddSetBitSet.erase(p);
      }
      // if current element has odd set bits, insert in set
      if (cnt & 1) {
        oddSetBitSet.insert(p);
      }

      if (oddSetBitSet.size() & 1) {
        // odd size, consider extreme elements (one of them can't be included)
        int first = *(oddSetBitSet.begin());
        int end = *(oddSetBitSet.rbegin());
        // consider elements after first
        currentAns = n - (first + 1);
        // consider elements before end
        currentAns = max(currentAns, end);
      } else {
        // all the elements can be included in the interval
        currentAns = n;
      }
      res.push_back(currentAns);
    }

    return res;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
      cin >> queries[i].first >> queries[i].second;
    }

    Solution solver;
    vector<int> res = solver.solve(n, q, a, queries);
    cout << "Case #" << i + 1 << ": ";
    for (int i = 0; i < q; ++i) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
  return 0;
}