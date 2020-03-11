#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        
        for (int i = 0; i < n; ++i) {
            if (i == headID) {
                continue;
            }
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int, int>> q;
        vector<int> visited(n, 0);
        q.push({headID, 0});
        int dist = 0;
        while (!q.empty()) {
            auto fr = q.front();
            int cur = fr.first;
            int c_dist = fr.second;
            visited[cur] = 1;
            q.pop();
            for (auto next: adj[cur]) {
                if (!visited[next]) {
                    q.push({next, c_dist + informTime[cur]});
                    dist = max(dist, c_dist + informTime[cur]);
                    visited[next] = 1;
                }
            }
        }
        return dist;
    }
};
int main () {
    Solution solver;
    vector<int> manager = {-1, 0, 0, 0, 0};
    vector<int> informTime = {10, 20, 30, 40, 50};
    cout << solver.numOfMinutes(5, 0, manager, informTime) << endl;
    return 0;
}