/*
 * CHEF and MEAN problem
 * https://www.codechef.com/JULY19A/problems/CHFM
 */

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

class Solution {
 public:
  int solve(istream &cin, ostream &cout, int caseNo) {
    int n;
    cin >> n;

    unordered_map <ll, int> cnt;
    ll sum = 0;
    ll x;
    for (int i = 0; i < n; i ++) {
      cin >> x;
      sum += x;
      if (cnt[x] == 0) {
        cnt[x] = (i + 1); // coin number
      }
    }

    if (sum % n != 0) {
      return 0;
    } else {
      if (cnt[sum/n] != 0) {
        return cnt[sum/n];
      } else {
        return 0;
      }
    }
    return -1;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  Solution solver;
  istream& in(cin);
  ostream& out(cout);

  int t;
  in >> t;
  for(int i = 0; i < t; ++i) {
      int res = solver.solve(in, out, i);
      if (!res) {
        out << "Impossible" << endl;
      } else {
        out << res << endl;
      }
  }

  return 0;
}