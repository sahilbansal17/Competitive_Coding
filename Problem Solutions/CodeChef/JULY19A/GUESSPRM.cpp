/*
 * GUESS THE PRIME
 * https://www.codechef.com/JULY19A/problems/GUESSPRM
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  /*
   * Function to find factors of a number
   * Time Complexity: O(sqrt(n))
   */
  vector<ll> factors(ll n) {
    vector<ll> res;
    if (n % 2 == 0) {
      res.push_back(2);
      while (n % 2 == 0) {
        n /= 2;
      }
    }
    for (int i = 3; i <= sqrt(n); i++) {
      if (n % i == 0) {
        res.push_back(i);
        while (n % i == 0) {
          n /= i;
        }
      }
    }
    if (n > 2) {
      res.push_back(n);
    }
    return res;
  }

 public:
  
  int solve() {
    ll x = 1000000;
    cout << "1 " << x << endl;
    cout.flush();

    ll y;
    cin >> y;

    // error handling
    if (y == -1) {
      return -1;
    }

    ll toFactor = 1ll*x*x - y;
    vector <ll> facs = factors(toFactor);

    int countFacs = facs.size();
    vector<int> moduloValues(countFacs);
    vector<int> toCountDistinct(countFacs);

    ll query2 = -1;
    for (int x = 1; x <= 1000000; x++) {
      for (int i = 0; i < countFacs; i++) {
        moduloValues[i] = (x * x) % facs[i];
        toCountDistinct[i] = moduloValues[i];
      }
      // check whether all factors will give
      // distinct values when considering (x^2 % facs[i])
      sort(toCountDistinct.begin(), toCountDistinct.end());
      int countDistinct = distance(toCountDistinct.begin(), 
                            unique(toCountDistinct.begin(), 
                              toCountDistinct.end()));
      if (countDistinct == countFacs) {
        query2 = x;
        break;
      }
    }

    cout << "1 " << query2 << endl;
    cout.flush();

    cin >> y;
    // error handling
    if (y == -1) {
      return -1;
    }

    for (int i = 0; i < countFacs; i ++) {
      if (moduloValues[i] == y) {
        return facs[i];
      }
    }

    return -1;
  }  

};

int main() {

  FAST_IO;
  
  Solution solver;

  int t;
  cin >> t;
  for(int i = 0; i < t; ++i) {
    int res = solver.solve();
    if (res == -1) {
      return 0;
    }
    cout << "2 " << res << endl;
    cout.flush();

    string verdict;
    cin >> verdict;
    if (verdict == "No") {
      return 0;
    }
  }

  return 0;
}