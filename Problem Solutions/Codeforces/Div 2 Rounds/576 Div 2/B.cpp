#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  double solve(double h, double l) {
    double ans = (l*l - h*h)/(2.0*h);
    return ans;
  }
};

int main() {
  FAST_IO;  
  double h, l;
  cin >> h >> l;

  Solution solver;
  cout << fixed;
  cout << setprecision(10);
  cout << solver.solve(h, l) << endl;
  return 0;
}