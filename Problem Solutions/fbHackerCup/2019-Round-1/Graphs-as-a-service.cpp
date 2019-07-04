#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000000;
typedef long long ll;

bool canBeRelaxed(int dist_u_k, int dist_k_v, int dist_u_v) {
  if (dist_u_v == MAX && dist_k_v == MAX) {
    return false;
  }
  if (dist_u_v > dist_u_k + dist_k_v) {
    return true;
  }
  return false;
}

typedef struct {
  int x; 
  int y;
  int z;
} edges;

bool isValidCase(vector<vector <int>> &adj, int n) {
  vector<vector<int>> dist(n + 1, vector<int> (n + 1));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      dist[i][j] = adj[i][j];
    }
  }

  for (int k = 1; k <= n; k ++) {
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        if (i == j) {
          continue;
        }
        if (canBeRelaxed(dist[i][k], dist[k][j], dist[i][j])) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) {
      if (adj[i][j] != MAX && adj[i][j] != dist[i][j]) {
        // cerr << i << " " << j << " " << dist[i][j] << endl;
        return false;
      }
    }
  }
  return true;
}

int main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/Users/sahilbansal/Downloads/graphs_as_a_service.txt", "r", stdin);
  // freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  // freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  // #endif

  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);

  int t;
  cin >> t;

  for (int k = 0; k < t; k ++) {
    
    int n, m;
    cin >> n >> m;

    int x, y, z;

    vector <vector <int>> adj(n + 1, vector<int> (n + 1, MAX));

    edges result[m];
    for (int i = 0; i < m; i ++) {
      cin >> x >> y >> z;
      adj[x][y] = z;
      adj[y][x] = z;
      // copy to result
      result[i].x = x;
      result[i].y = y;
      result[i].z = z;
    }

    bool possible = isValidCase(adj, n);
    cout << "Case #" << k + 1 << ": ";
    if (!possible) {
      cout << "Impossible" << endl;
    }
    else {
      cout << m << endl;
      for (int i = 0; i < m; i ++) {
        cout << result[i].x << " " << result[i].y << " " << result[i].z << endl;
      }
    }
  } 

  return 0;
}