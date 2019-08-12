/*
 * https://www.codechef.com/AUG19A/problems/MAXEXPR
 * Subtask 1: rewrite expression in terms of one variable and derivate

 * Subtask 2 and 4: k[i] = 1 and c[i] = 0 for each valid i
   Just output (n + 1) zeroes

 * Subtask 3: k[i] = 1 for all i
   make all terms inside square root equal

 * Subtask 5: Use the concept of constrained optimization using langrange multipler
   gradient of optimized function = lambda(gradient of constraint function)
   find lambda
   use this to get x[i] values
*/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  void solve(int n, vector<double> k, vector<double> c) {
    if (n == 2) {
      double x1 = (c[1]*k[1]*k[1] - c[0]*k[0]*k[0])/(k[0]*(k[0] + k[1]));
      double x2 = -(k[0]/k[1])*x1;
      if (x1 + c[0] < 0 || x2 + c[1] < 0) {
        cout << "-1" << endl;
      } else {
        double res = sqrt(x1 + c[0]) + sqrt(x2 + c[1]);
        cout << res << " " << x1 << " " << x2 << endl;
      }
      return;
    }

    bool kAllOne = true;
    bool cAllZero = true;
    for (int i = 0; i < n; ++i) {
      if (k[i] != 1) {
        kAllOne = false;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (c[i] != 0) {
        cAllZero = false;
      }
    }
    if (cAllZero) {
      for (int i = 0; i <= n; ++i) {
        cout << "0 ";
      }
      cout << endl;
      return;
    } else if (kAllOne) {
      double negSum = 0, posSum = 0;
      for (int i = 0; i < n; ++i) {
        if (c[i] < 0) {
          negSum += abs(c[i]);
        } else {
          posSum += c[i];
        }
      }
      if (posSum >= negSum) {
        double ans = n*sqrt((posSum - negSum)/n);
        cout << ans << " ";

        double termInsideRoot = (posSum - negSum)/n;
        for (int i = 0; i < n; ++i) {
          double cur = termInsideRoot - c[i];
          cout << cur << " ";
        }
      } else {
        cout << "-1";
      }
      cout << endl;
      return;
    }

    // general case
    double ckSum = 0;
    double kInverseSum = 0;
    vector<double> xfinal;
    for (int i = 0; i < n; ++i) {
      ckSum += (c[i]*k[i]);
      kInverseSum += (1/k[i]);
    }

    double finalVal = 0;
    for (int i = 0; i < n; ++i) {
      double current = (ckSum/(k[i]*k[i]*kInverseSum)) - c[i];
      xfinal.push_back(current);
      if (current + c[i] < 0) {
        cout << "-1" << endl;
        return;
      }
      finalVal += sqrt(current + c[i]);
    }

    cout << finalVal << " ";
    for (int i = 0; i < n; ++i) {
      cout << xfinal[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<double> k(n), c(n);
    for (int j = 0; j < n; ++j) {
      cin >> k[j];
    }
    for (int j = 0; j < n; ++j) {
      cin >> c[j];
    }

    cout << fixed << setprecision(3);
    Solution solver;
    solver.solve(n, k, c);
  }
  
  return 0;
}