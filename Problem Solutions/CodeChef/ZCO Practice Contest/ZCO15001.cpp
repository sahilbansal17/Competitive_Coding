#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a) {
    bool isPalindrome[n][n];
    memset(isPalindrome, 0, sizeof(isPalindrome));
    // length 1
    for (int i = 0; i < n; ++i) {
      isPalindrome[i][i] = 1;
    }
    // length 2
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == a[i + 1]) {
        isPalindrome[i][i + 1] = 1;
      }
    }
    // length >= 3
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        isPalindrome[i][j] = (a[i] == a[j]) && isPalindrome[i + 1][j - 1];
      }
    }
    /*/
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cerr << isPalindrome[i][j] << " ";
      }
      cerr << endl;
    }
    //*/

    int cost[n][n]; // cost[i][j] is the min. no. of palindromic sequences 
                    // for subarray from a[i...j]
    memset(cost, 0, sizeof(cost));
    // length 1
    for (int i = 0; i < n; ++i) {
      cost[i][i] = 1;
    }
    // length 2
    for (int i = 0; i < n - 1; ++i) {
      if (isPalindrome[i][i + 1]) {
        cost[i][i + 1] = 1;
      } else {
        cost[i][i + 1] = 2;
      }
    }
    // length >= 3
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        if (isPalindrome[i][j]) {
          cost[i][j] = 1;
          continue;
        }
        cost[i][j] = len;
        for (int k = i; k < j; ++k) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j]);
        }
      }
    }
    /*/
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cerr << cost[i][j] << " ";
      }
      cerr << endl;
    }
    //*/
    return cost[0][n - 1];
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
  cout << solver.solve(n, a) << endl;
  return 0;
}