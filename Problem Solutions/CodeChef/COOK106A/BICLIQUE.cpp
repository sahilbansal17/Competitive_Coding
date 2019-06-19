#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main(){

    FAST_IO;    

    int n, m, k;
    cin >> n >> m >> k;

    int adj[MAX][MAX];
    memset(adj, 0, sizeof(adj));

    vector <int> adj_list[MAX];
    int x, y;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            if (adj_list[i].size() < k || adj_list[j].size() < k) {
                continue;
            }
            int count = 0;
            for (int k = 1; k <= n; k ++) {
                if (k == i || k == j) {
                    continue;
                }
                if (adj[i][k] == 1 && adj[j][k] == 1) {
                    count ++;
                }
            }
            if (count >= k) {
                // cerr << i << " " << j << endl;
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}