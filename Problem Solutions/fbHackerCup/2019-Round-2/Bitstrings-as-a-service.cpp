#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
const int MOD = 1000000007;
typedef long long ll;

// #define TEST 1
#define SUBMIT 1

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

class Solution {
 public:
  vector<int> solve(int n, int m, vector<pair<int, int>> c) {
    vector<pair<int, pair<int, int>>> cc(m);
    for (int i = 0; i < m; i ++) {
      cc[i].first = c[i].second - c[i].first + 1;
      cc[i].second.first = c[i].first;
      cc[i].second.second = c[i].second;
    }
    // sort(c.begin(), c.end());
    sort(cc.begin(), cc.end());
    vector<int> res(n, -1);

    UnionFind UF(n);
    int countZ = 0, countO = 0;
    for (int i = 0; i < m; i ++) {
      int s = cc[i].second.first;
      int e = cc[i].second.second;
      int le = s - 1, re = e - 1;
      while (le < re) {
        if (!UF.isSameSet(le, re)) {
          UF.unionSet(le, re);
        }
        le ++;
        re --;
      }
    }

    int cur = 0;
    vector<pair<int, int>> sz(n);
    for (int i = 0; i < n; i ++) {
      sz[i].first = UF.sizeOfSet(i);
      sz[i].second = i;
    }
    sort(sz.begin(), sz.end());
    reverse(sz.begin(), sz.end());

    int bestDiff = INT_MAX;
    for (int i = 0; i < n; i ++) {
      int idx = sz[i].second;
      if (res[idx] == -1) {
        int ss = sz[i].first;
        if (abs(ss + countZ - countO) < bestDiff) {
          bestDiff = abs(ss + countZ - countO);
          countZ += ss;
          cur = 0;
        } else {
          bestDiff = abs(ss + countO - countZ);
          countO += ss;
          cur = 1;
        }
        for (int j = 0; j < n; j ++) {
          if (UF.isSameSet(idx, j)) {
            res[j] = cur;
          }
        }
      }
    }
    return res;
  }
};

int main(){

  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);

  #ifdef TEST
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  #ifdef SUBMIT
  freopen("/Users/sahilbansal/Downloads/bitstrings_as_a_service.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif 

  int t;
  cin >> t;

  Solution solver;
  for (int i = 0; i < t; i ++) {
    vector<int> res;

    int n, m, x, y;
    cin >> n >> m;
    vector<pair<int, int>> c;
    for (int i = 0; i < m; i ++) {
      cin >> x >> y;
      c.push_back({x, y});
    }

    res = solver.solve(n, m, c);
    cout << "Case #" << i + 1 << ": ";
    for (int i = 0; i < n; i ++) {
      cout << res[i];
    } 
    cout << endl;
  } 

  return 0;
}