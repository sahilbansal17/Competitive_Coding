#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n, vector<int> a) {
    // Stores result for subarray arr[0..i], i.e., 
    // maximum possible sum in subarray arr[0..i] 
    // such that no three elements are consecutive.
    vector<int> dp(n); 
  
    // Base cases (process first three elements) 
    if (n >= 1) {
      dp[0] = a[0];
    } 
  
    if (n >= 2) {
      dp[1] = a[0] + a[1]; 
    }
  
    if (n > 2) {
      dp[2] = max(dp[1], max(a[1] + a[2], a[0] + a[2])); 
    }
  
    // Process rest of the elements 
    // We have three cases 
    // 1) Exclude a[i], i.e., dp[i] = dp[i-1] 
    // 2) Exclude a[i-1], i.e., dp[i] = dp[i-2] + a[i] 
    // 3) Exclude a[i-2], i.e., dp[i] = dp[i-3] + a[i] + a[i-1] 
    for (int i = 3; i < n; i++) {
      dp[i] = max(max(dp[i - 1], dp[i - 2] + a[i]), 
                     a[i] + a[i - 1] + dp[i - 3]); 
    }
    return dp[n - 1];
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
  cout << solver.solve(n, a);
  return 0;
}