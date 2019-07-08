/*
 * Codeforces 572 Div 2
 * Competitive Coding repository: https://github.com/sahilbansal17/Competitive_Coding
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  void solve(int n, vector<int> a) {
    vector <int> res(n, 0);
    sort(a.begin(), a.end());

    int mid = n/2;
    int k = 0;
    res[mid] = a[k];
    int left = mid - 1, right = mid + 1;
    while (k < n && left >= 0 && right < n) {
      k ++;
      res[left] = a[k];
      k ++;
      res[right] = a[k];
      left --;
      right ++;
    }
    if (left == 0) {
      k ++;
      res[0] = a[k];
    }

    if (res[0] < res[1] + res[n - 1] &&
        res[n - 1] < res[n - 2] + res[0]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
      return;
    }
    for (int i = 0; i < n; i ++) {
      cout << res[i] << " ";
    }
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
  
  int n;
  cin >> n;

  vector<int> a(n, 0); 
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }
  solver.solve(n, a);

  return 0;
}