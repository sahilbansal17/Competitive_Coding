/*
 * Maximum and Minimum
 * https://www.codechef.com/JULY19A/problems/MXMN
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MAX = 9223372036854775807LL;
const ll MOD = 998244353LL;

const int N = 2010;

/*  Union-Find Disjoint Sets Library written in OOP manner
 *  using both path compression and union by rank heuristics
 *  source: CP-3 by Steven Halim
 */
class UnionFind {
 private:
    vector<int> p, rank, setSize; 
    int numSets;
 public:
    UnionFind(int n){
        setSize.assign(n, 1); 
        numSets = n; 
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i; 
    }
    int findSet(int i){ 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }
    bool isSameSet(int i, int j){ 
        return findSet(i) == findSet(j); 
    }
    void unionSet(int i, int j){ 
        numSets--; 
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]){
            p[y] = x; 
            setSize[x] += setSize[y];
        }
        else{ 
            p[x] = y; 
            setSize[y] += setSize[x];
            if(rank[x] == rank[y]) 
                rank[y]++; 
        } 
    }
    int numDisjointSets(){ 
        return numSets; 
    }
    int sizeOfSet(int i){ 
        return setSize[findSet(i)]; 
    }
};

// solves subtask 1
class Solution {
 private:
  // minimum spanning trees
  vector<pair<int, int>> st1[N];
  vector<pair<int, int>> st2[N];  
  ll f1[N][N];
  ll f2[N][N];
  int subtask = 1;
  int subtask2Result = 0;
  /*  Function to find the minimum spanning tree
   *  V: number of vertices
   *  e: number of edges
   *  edges: vector storing the edges in the graph
   */
  void spanningTree(int V, int e, 
                  vector<pair<int, pair<int, int>>> edges,
                  int treeNumber) {

    // sort the edges based on their weight
    // for convenience, added weight as first in the edges pair
    sort(edges.begin(), edges.end());
    // initialize UnionFind object equal to the no. of vertices
    UnionFind subsets(V + 1);

    // process all the edges
    for (int edge_idx = 0; edge_idx < e; edge_idx ++) {
      pair<int, pair<int, int>> current_edge = edges[edge_idx];

      int weight = current_edge.first;
      int first_node = current_edge.second.first;
      int second_node = current_edge.second.second;

      // if current_edge doesn't form a cycle
      if (!subsets.isSameSet(first_node, second_node)) {
        // cerr << "Joining " << first_node << " and " << second_node << endl;
        // connect the nodes, i.e. add both the nodes in the same subset
        subsets.unionSet(first_node, second_node);
        // edge between the nodes in spanning tree
        if (treeNumber == 1) {
          st1[first_node].push_back({second_node, weight});
          st1[second_node].push_back({first_node, weight}); 
        } else {
          st2[first_node].push_back({second_node, weight});
          st2[second_node].push_back({first_node, weight}); 
        }
      }
    }

  }
  
  void fillEntriesDFS(int root, int maxEdge, int current, 
                    int treeNumber, vector<int> &visited) {
    visited[current] = true;
    if (treeNumber == 1) {
      if (subtask == 1) {
        f1[root][current] = maxEdge;
      } else {
        if (current > root) {
          // identical graphs
          subtask2Result += ((1ll * maxEdge * maxEdge) % MOD);
          subtask2Result %= MOD;
        }
      }
      for (int i = 0; i < st1[current].size(); i ++) {
        int next, weight;
        next = st1[current][i].first;
        weight = st1[current][i].second;
        if (!visited[next]) {
          fillEntriesDFS(root, max(maxEdge, weight), next,
                        treeNumber, visited);
        }
      }
    } else {
      if (subtask == 1) {
        f2[root][current] = maxEdge;
      } else {
        if (current > root) {
          // identical graphs
          subtask2Result += ((1ll * maxEdge * maxEdge) % MOD);
          subtask2Result %= MOD;
        }
      }
      for (int i = 0; i < st2[current].size(); i ++) {
        int next, weight;
        next = st2[current][i].first;
        weight = st2[current][i].second;
        if (!visited[next]) {
          fillEntriesDFS(root, max(maxEdge, weight), next,
                        treeNumber, visited);
        }
      }
    }
  }
  
 public:
  int solve(int n, vector<pair<int, pair<int, int>>> &g1, 
                  vector<pair<int, pair<int, int>>> &g2) {
    // no. of edges should be 4*n (double in undirected graph)
    spanningTree(n, 4*n, g1, 1);
    spanningTree(n, 4*n, g2, 2);

    if (n != 2000) {
      subtask = 2; 
      // identical graphs
    }

    for (int i = 1; i <= n; i ++) {
      vector<int> visited1(n + 1, 0);
      vector<int> visited2(n + 1, 0);
      fillEntriesDFS(i, 0, i, 1, visited1);
      if (subtask == 1) {
        // if first subtask, then only calculate again
        fillEntriesDFS(i, 0, i, 2, visited2);
      }
    }

    /*/
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= n; j ++) {
        cerr << f1[i][j] << " ";
      }
      cerr << endl;
    }
    //*/

    /*/
    for (int i = 1; i <= n; i ++) {
      cerr << i << ": ";
      for (int j = 0; j < st1[i].size(); j ++) {
        cerr << st1[i][j].first << " ";
      }
      cerr << endl;
    }
    //*/
    if (subtask == 2) {
      return subtask2Result;
    }

    ll res = 0, current;
    for (int i = 1; i <= n - 1; i ++) {
      for (int j = i + 1; j <= n; j ++) {
        current = (1ll * f1[i][j] * f2[i][j]) % MOD;
        // cerr << f2[i][j] << " ";
        res += current;
        res %= MOD;
      }
      // cerr << endl;
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
  
  Solution solver;

  int n, m;
  cin >> n >> m;

  int u, v, w;
  vector<pair<int, pair<int, int>>> adj1, adj2;

  for (int i = 0; i < m; i ++) {
    cin >> u >> v >> w;
    adj1.push_back({w, {v, u}});
    adj1.push_back({w, {u, v}});
  }
  for (int i = 0; i < m; i ++) {
    cin >> u >> v >> w;
    adj2.push_back({w, {v, u}});
    adj2.push_back({w, {u, v}});
  }

  cout << solver.solve(n, adj1, adj2);
  return 0;
}