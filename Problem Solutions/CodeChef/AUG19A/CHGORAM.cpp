/* 
 * https://www.codechef.com/AUG19A/problems/CHGORAM
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
class Solution {
 public:
  ll solve(int n, vector<int> p, vector<int> adj[]) {
    if (n <= 2) {
      return 0;
    }

    // subtask 3: star graph
    bool star = false;
    int cnt = 0;
    int starVertex = -1;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      if (adj[i].size() != 1) {
        starVertex = i;
        ++cnt;
      }
    }
    if (cnt == 1) {
      star = true;
    }
    if (star) {
      if (p[1] == 2) {
        res = 1ll * (starVertex - 1) * (n - starVertex);
      } else if (p[1] == 1) {
        for (int x = starVertex + 1; x <= n; ++x) {
          res += 1ll * (n - x);
        }
      } else if (p[1] == 3) {
        for (int x = 1; x < starVertex; ++x) {
          res += 1ll * (x - 1);
        }
      }
      return res;
    }

    // subtask 4: path graph
    bool path = false;
    int cnt1 = 0, cnt2 = 0;
    vector<int> ends;
    for (int i = 1; i <= n; ++i) {
      if (adj[i].size() == 1) {
        ends.push_back(i);
        ++cnt1;
      } else if (adj[i].size() == 2) {
        ++cnt2;
      }
    }
    if (cnt1 == 2 && cnt2 == n - 2) {
      path = true;
    }
    /*
    if (path) {
      // path graph
      int end1 = ends[0];
      int end2 = ends[1];

      vector<int> line;
      line.push_back(end1);
      int cur = end1;
      int prev = end1;
      while (cur != end2) {
        int next = adj[cur][0];
        if (next == prev) {
          next = adj[cur][1];
        }
        line.push_back(next);
        prev = cur;
        cur = next;
      }
      line.push_back(end2);

      for (int i = 0; i < n; ++i) {
        cerr << line[i] << " ";
      }
      cerr << endl;
    }
    */
    return 0;
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

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<int> p(3);
    for (int j = 0; j < 3; ++j) {
      cin >> p[j];
    }

    int u, v;
    vector<int> adj[MAX];
    for (int j = 0; j < n - 1; ++j) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    Solution solver;
    cout << solver.solve(n, p, adj) << endl;
  }
  return 0;
}