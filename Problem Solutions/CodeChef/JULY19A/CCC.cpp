/*
 * HIT THE COCONUTS
 * https://www.codechef.com/JULY19A/problems/CCC
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int N = 1010;
class Solution {
 private:
  // best answer for given length
  int dp[N];
  vector<int> prefix;
 public:
  // constructor
  Solution() {
    for (int i = 0; i < N; i ++) {
      dp[i] = -1;
    }
  }

  void buildPrefixSum(int n, vector<int> &a) {
    prefix.push_back(a[0]);
    for (int i = 1; i < n; i ++) {
      prefix.push_back(prefix[i - 1] + a[i]);
    }
  }

  ll solveSubtask1(int n, vector<int> &a) {

    sort(a.begin(), a.end());
    int res = INT_MAX;
    for (int i = 0; i < n; i ++) {
      res = min(res, (n - i)*a[i]);
    }
    return res;
  }

  ll solveGeneral(int z, vector<int> &a, int start, int end, int subtract) {
    if (start > end) {
      return 0;
    }
    int len = (end - start + 1);
    if (dp[len] != -1) {
      #ifdef DEBUG
      cerr << "Done: " << start << "->" << end << " z: " << z;
      cerr << " cost: " << dp[len] << endl;
      #endif

      return dp[len];
    }
    #ifdef DEBUG
    cerr << start << "->" << end << " z: " << z << endl;
    #endif

    int cost = INT_MAX;
    
    for (int i = start; i <= end; i ++) {
      #ifdef DEBUG
      cerr << a[i] - subtract << " ";
      #endif
      int n = (end - start + 1);
      // map i to i - start
      int currentCost = (n - (i - start)) * (a[i] - subtract);
      if (currentCost < cost) {
        cost = (n - (i - start))*(a[i] - subtract);
      }
    }
    #ifdef DEBUG
    cerr << endl;
    #endif

    // subTask 1, directly return the result
    if (z == 1) {
      
      #ifdef DEBUG
      cerr << "Z = 1 => " << cost << endl;
      #endif
      dp[len] = cost;
      return cost;
    }

    int minCost = INT_MAX;

    // consider the elements after index (z - 1) from start
    // the i-th index is the first cocunut to be broken
    for (int i = start + z - 1; i <= end; i ++) {
      int currentCost;
      #ifdef DEBUG
      cerr << a[i] - subtract << " ";
      #endif
      if (i >= z) {
        currentCost = prefix[i] - prefix[i - z] - z*subtract;
      } else {
        currentCost = prefix[i] - z*subtract;
      }

      currentCost += (a[i] - subtract) * (len - (i - start) - 1);
      
      if (currentCost < minCost) {
        minCost = currentCost;
      }
    }
    #ifdef DEBUG
    cerr << endl;
    cerr << "Minimum Cost after considering all z: " << minCost << endl;
    cerr << endl;
    cerr << "Loop start: " << start << "->" << end << endl;
    #endif
    // consider the elements before index (z - 1)
    for (int i = start + z - 2; i >= start; i --) {
      // considering the first hit at i
      // also hitting all cocunuts before it
      int currentCost;
      // elements before i and including i
      if (start >= 1) {
        currentCost = (prefix[i] - prefix[start - 1]) - (i - start + 1)*subtract;
      } else {
        currentCost = (prefix[i]) - (i - start + 1)*subtract;
      }
      // after i, also hit a[i] times
      #ifdef DEBUG
      cerr << start << "->" << end << " " << "z:" << z << " ";
      cerr << "Current cost 1: " << currentCost << endl;
      #endif
      currentCost += (a[i] - subtract) * (len - (i - start) - 1);
      #ifdef DEBUG
      cerr << "Current Cost 2: " << (a[i] - subtract) * (len - (i - start) - 1) << endl;
      #endif
      // solve in the right part of the array
      // Z' = z - (i-start + 1)
      // array updated to A', with all elements after i, subtracted
      // by value of a[i]
      currentCost += solveGeneral(z - (i - start) - 1, a, i + 1, end, subtract + a[i]);
      #ifdef DEBUG
      cerr << "Current Cost: " ;
      cerr << "i = " << start + z - 2 << ": " << currentCost << endl;
      cerr << endl;
      #endif
      if (currentCost < minCost) {
        minCost = currentCost;
      }
    }
    #ifdef DEBUG
    cerr << "Best Cost: " << minCost << endl << endl;
    #endif
    // store dp value
    dp[len] = minCost;
    return minCost;
  }

};

int main() {

  FAST_IO;
  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  int t;
  cin >> t;
  for(int i = 0; i < t; ++i) {
    int n, z;
    cin >> n >> z;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // sort here itself
    sort(a.begin(), a.end());

    // create new solver each time to clear the DP table!
    Solution solver;
    solver.buildPrefixSum(n, a);

    int ans = solver.solveGeneral(z, a, 0, n - 1, 0);
    cout << ans << endl;
  }

  return 0;
}