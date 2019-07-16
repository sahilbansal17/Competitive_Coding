/*
 * CodeChef War
 * https://www.codechef.com/JULY19A/problems/CHFWAR
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

// #define DEBUG 1
// #define REDUCTION_DEBUG 1
// #define SUBTASK1 1
#define SUBTASK2 1

class Solution {
 private:
 
  // FOR SUBTASK 1
  int simulatePowerReduce(int n, int p, vector<int> &a) {
   
    #ifdef DEBUG
    cerr << n << " " << p + 1 << endl;
    #endif 

    if (n == 2) {
      // no power reduction
      return 0;
    }
    vector<int> alive(n, 1);
    int aliveCount = n;
    int current = 0, reduction = 0, next;
    // Josh cannot attack
    if (current == p) {
      current = (current + 1) % n;
    }
    while (aliveCount != 2) {
      next = (current + 1) % n;
      while (!alive[next]) {
        next = (next + 1) % n;
      }
      if (next == p) {
        // reduce power
        reduction += a[current];
        #ifdef DEBUG
        cerr << current + 1 << " ";
        #endif 
      } else {
        // mark as dead
        alive[next] = 0;
        aliveCount --;
      }

      current = (next + 1) % n;
      // Josh cannot attack
      // dead member cannot attack
      while (current == p || !alive[current]) {
        current = (current + 1) % n;
      }
    }
    #ifdef DEBUG
    cerr << endl << endl;
    #endif

    #ifdef REDUCTION_DEBUG
    cerr << reduction << endl;
    #endif
    return reduction;
  }

  // FOR SUBTASK 2, per position: O(log N) complexity
  // TOTAL COMPLEXITY: O(N log N)
  int calculatePowerReduce(int n, int p, vector<int> &a) {
    if (n == 2) {
      return 0;
    }

    int reduction = 0;

    #ifdef DEBUG
    cerr << n << " " << p + 1 << endl;
    #endif
    if (p == n - 1) {
      // only first AP
      int start = 0, end = p - 1;
      int cd = 1; // common difference
      int len = 1 + (end - start)/cd;
      while (start < end) {
        // till only first number remains
        if (len & 1) {
          #ifdef DEBUG
          cerr << end + 1 << " ";
          #endif
          reduction += a[end];
        } else {
          end = end - cd;
        }
        cd *= 2;
        len = 1 + (end - start)/cd;
      }
    } else {
      // 2 AP's present
      int firstApStart = 0;
      int firstApEnd = p - 1;

      int secondApStart = p;
      int secondApEnd = n - 2;

      int commonDifference = 1; // doubles at each iteration

      int lenAp1 = 1 + (firstApEnd - firstApStart)/commonDifference;
      int lenAp2 = 1 + (secondApEnd - secondApStart)/commonDifference;

      // bool firstApFirstKilledRecently = false;
      while (lenAp1 >= 1 || (lenAp2 > 1)) {

        // if length of first AP is odd, last term attacks D
        if (lenAp1 & 1) {
          #ifdef DEBUG
          cerr << firstApEnd + 1 << " ";
          #endif
          reduction += a[firstApEnd];
        } else if (lenAp1 != 0) {
          // even length => last term killed
          firstApEnd = firstApEnd - commonDifference;
        } 

        // if length of second AP is odd, 
        // its last term kills first term of first AP
        if (lenAp2 & 1) {
          if (lenAp1 == 0) {
            // last of AP2 attacks D
            #ifdef DEBUG
            cerr << secondApEnd + 1 << " ";
            #endif
            reduction += a[secondApEnd];
          } else {
            firstApStart = firstApStart + 2*commonDifference;
          }
        } else {
          // even length => last term killed
          secondApEnd = secondApEnd - commonDifference;
        }

        commonDifference *= 2;
        if (firstApStart > firstApEnd) {
          lenAp1 = 0;
        } else {
          lenAp1 = 1 + (firstApEnd - firstApStart)/commonDifference;
        }
        if (secondApStart > secondApEnd) {
          // one element will always be there
          lenAp2 = 1;
        } else {
          lenAp2 = 1 + (secondApEnd - secondApStart)/commonDifference;
        }
      }
    }
    #ifdef DEBUG
    cerr << endl << endl;
    #endif

    #ifdef REDUCTION_DEBUG
    cerr << reduction << endl;
    #endif

    return reduction;
  }
 public:

  pair<int, int> solve(int n, int f, vector<int> &a) {
    pair<int, int> res = {INT_MAX, INT_MAX};

    int minPower = *min_element(a.begin(), a.end());
    if (minPower > f) {
      // cerr << minPower << endl;
      // not possible case
      return res;
    }

    // consider all possible positions
    for (int p = 0; p < n; p++) {
      // next position should have soldier
      // with power <= f

      /*
       * FOR SUBTASK 1
       */
      
      #ifdef SUBTASK1
      // copy with n positions
      vector<int> c(n, 0);
      // update array with position p
      int k = 0;
      for (int i = 0; i < p; i++) {
        c[i] = a[k];
        k ++;
      }
      // a[p] = 0;
      for (int i = p + 1; i < n; i++) {
        c[i] = a[k];
        k ++;
      }
      /*/
      for (int i = 0; i < n; i ++) {
        cerr << c[i] << " ";
      }
      cerr << endl;
      //*/
      int nextIndex = (p + 1) % n;
      if (c[nextIndex] <= f) {
        // brute force to find how much power will be reduced
        int currentReduced = simulatePowerReduce(n, p, c);
        int currentRequired = f + currentReduced;
        if (currentRequired < res.second) {
          res.second = currentRequired;
          res.first = (p + 1);
        }
      }
      #endif

      #ifdef SUBTASK2
      if ((p < n - 1 && a[p] <= f)
        || (p == n - 1 && a[0] <= f)) {
      
        int currentReduced = calculatePowerReduce(n, p, a);
        int currentRequired = f + currentReduced;
        if (currentRequired < res.second) {
          res.second = currentRequired;
          res.first = (p + 1);
        }
      }
      #endif 
    }

    // cerr << endl;
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
  
  Solution solver;

  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int n, f;
    cin >> n;

    vector<int> a(n - 1);
    for (int j = 0; j < n - 1; j++) {
      cin >> a[j];
    }
    cin >> f;

    pair<int, int> res = solver.solve(n, f, a);
    if (res.first == INT_MAX && res.second == INT_MAX) {
      cout << "impossible" << endl;
    } else {
      cout << "possible" << endl;
      cout << res.first << " " << res.second << endl;
    }
  }

  return 0;
}