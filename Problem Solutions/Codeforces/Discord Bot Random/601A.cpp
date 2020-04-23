#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

int main() {
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> rail_graph(n, vector<int> (n, 0));
    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        --x;
        --y;
        rail_graph[x][y] = 1;
        rail_graph[y][x] = 1;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    int rail_dist = -1;
    int road_dist = -1;
    vector<int> vis(n, 0);
    vis[0] = 1;
    while (!q.empty()) {
        auto fr = q.front();
        int city = fr.first;
        int dist = fr.second;
        q.pop();
        if (city == n - 1) {
            // reached
            rail_dist = dist;
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (rail_graph[city][i] == 1 && !vis[i]) {
                vis[i] = 1;
                q.push({i, dist + 1});
            }
        }
    }
    // clear the queue for re-usage
    while (!q.empty()) {
        q.pop();
    }
    vis.assign(n, 0);
    q.push({0, 0});
    vis[0] = 1;
    while (!q.empty()) {
        auto fr = q.front();
        int city = fr.first;
        int dist = fr.second;
        q.pop();
        if (city == n - 1) {
            road_dist = dist;
            break;
        }
        for (int next = 0; next < n; ++next) {
            if (!rail_graph[city][next] && !vis[next]) {
                // there is a road between them
                vis[next] = 1;
                q.push({next, dist + 1});
            }
        }
    }

    // clear the queue
    while (!q.empty()) {
        q.pop();
    }

    if (road_dist == -1 || rail_dist == -1) {
        cout << -1 << endl;
    } else {
        cout << max(road_dist, rail_dist) << endl;
    }
    return 0;
}