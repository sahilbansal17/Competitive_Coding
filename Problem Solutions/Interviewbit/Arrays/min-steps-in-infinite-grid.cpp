/*
 * https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
class Solution {
 public:
    int coverPoints(vector<int> &A, vector<int> &B);
};

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
  int res = 0;
  int n = A.size();
  int prevX = A[0];
  int prevY = B[0];
  for (int i = 1; i < n; ++i) {
    res += max(abs(A[i] - prevX), abs(B[i] - prevY));
    prevX = A[i];
    prevY = B[i];
  }
  return res;
}


int main() {
  FAST_IO;
  
  vector<int> A = {0, 1, 2};
  vector<int> B = {0, 1, 2};

  Solution solver;
  int res = solver.coverPoints(A, B);
  cout << endl;
  cout << res << endl;

  return 0;
}