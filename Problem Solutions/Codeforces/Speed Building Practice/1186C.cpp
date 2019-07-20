#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(string &a, string &b) {
    int m = b.length();
    int count = 0; // count of set bits in b
    for (int i = 0; i < m; ++i) {
      if (b[i] == '1') {
        ++count;
      }
    }
    // count of set bits in window size of m in a
    int countWindow = 0;
    int n = a.length();
    for (int i = 0; i < m; ++i) {
      if (a[i] == '1') {
        ++countWindow;
      }
    }

    int res = 0; // required count of substrings
    if (countWindow % 2 == count % 2) {
      ++res;
    }
    for (int i = m; i < n; ++i) {
      if (a[i - m] == '1') {
        --countWindow;
      }
      if (a[i] == '1') {
        ++countWindow;
      }
      if (countWindow % 2 == count % 2) {
        ++res;
      }
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

  string a;
  cin >> a;

  string b;
  cin >> b;

  Solution solver;
  cout << solver.solve(a, b) << endl;
  return 0;
}