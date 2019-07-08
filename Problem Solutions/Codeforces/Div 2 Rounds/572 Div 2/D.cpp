/*
 * Codeforces 572 Div 2
 * Competitive Coding repository: https://github.com/sahilbansal17/Competitive_Coding
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  vector<int> adj[100010];
 public:
  void solve(int n) {
    int x, y;
    for (int i = 0; i < n - 1; i ++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i ++) {
      if (adj[i].size() == 2) {
        cout << "NO" << endl;
        return ;
      }
    }
    cout << "YES" << endl;
    return;
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

  solver.solve(n);

  return 0;
}