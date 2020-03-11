#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n + 1];
        for (auto edge: edges) {
            int x = edge[0];
            int y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> visited(n + 1, 0);
        int root = 1;
        queue<pair<int, pair<int, int>>> q;
        q.push({root, {0, 1}});
        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            int cur = fr.first;
            int c_dist = fr.second.first;
            int c_val = fr.second.second;
            visited[cur] = 1;
            int sz = 0;
            for (auto next: adj[cur]) {
                if (!visited[next]) {
                    ++sz;
                }
            }
            if (cur == target) {
                if (c_dist > t || ((c_dist < t) && (sz > 0))) {
                    return 0;
                } else {
                    return 1.0/c_val;
                }
            }
            for (auto next: adj[cur]) {
                if (!visited[next]) {
                    q.push({next, {c_dist + 1, c_val * sz}});
                    visited[next] = 1;
                }
            }
        }
        return 0;
    }
};
int main () {
    Solution solver;
    vector<vector<int>> edges = {{1, 2}, {1, 3}};
    cout << solver.frogPosition(3, edges, 10, 3) << endl;
    return 0;
}