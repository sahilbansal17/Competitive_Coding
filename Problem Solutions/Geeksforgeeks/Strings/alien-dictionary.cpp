/*
 * https://practice.geeksforgeeks.org/problems/alien-dictionary/1
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

vector<int> adj[26];
vector<int> res;
void dfs(int i, vector<bool> &visited) {
  visited[i] = 1;
  for (auto next: adj[i]) {
    if (!visited[next]) {
      dfs(next, visited);
    }
  }
  res.push_back(i);
}

int main(){
  FAST_IO;    

  ll t;
  cin >> t;

  while (t --) {
    int n, k;
    cin >> n >> k;

    vector<string> vs(n);
    for (int i = 0; i < n; ++i) {
      cin >> vs[i];
    }

    for (int i = 0; i < n - 1; ++i) {
      int n1 = vs[i].length();
      int n2 = vs[i + 1].length();
      int p = 0;
      while (p < n1 && p < n2 && vs[i][p] == vs[i + 1][p]) {
        ++p;
      }
      if (p == n1 || p == n2) {
        continue;
      }
      int a = vs[i][p] - 'a';
      int b = vs[i + 1][p] - 'a';
      // a before b
      adj[a].push_back(b);
    }

    // perform topological sorting on graph
    vector<bool> visited(k, 0);
    for (int i = 0; i < k; ++i) {
      if (!visited[i]) {
        dfs(i, visited);
      }
    }

    reverse(res.begin(), res.end());
    string ans;
    for (int i = 0; i < res.size(); ++i) {
      ans += ('a' + res[i]);
    }

    cout << ans << endl;

    res.clear();
    for (int i = 0; i < 26; ++i) {
      adj[i].clear();
    }
  }
  return 0;
}