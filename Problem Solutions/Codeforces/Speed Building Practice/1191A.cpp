#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  pair<int, char> solve(int n) {
    int mod = n % 4;
    pair<int, char> res;
    switch(mod) {
      case 0:
        res.first = 1;
        res.second = 'A';
        break;
      case 1:
        res.first = 0;
        res.second = 'A';
        break;
      case 2:
        res.first = 1;
        res.second = 'B';
        break;
      case 3:
        res.first = 2;
        res.second = 'A';
        break;
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

  int n;
  cin >> n;
  Solution solver;  
  pair<int, char> res = solver.solve(n);
  cout << res.first << " " << res.second << endl;
  return 0;
}