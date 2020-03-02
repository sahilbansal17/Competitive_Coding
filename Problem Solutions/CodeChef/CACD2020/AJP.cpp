#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int dx[4] = {-1, 0,  0, +1};
int dy[4] = {0, -1, +1,  0};

bool isSafe(int r, int c, int n, int m) {
    if (r >= 1 && c >= 1 && r <= n && c <= m) {
        return true;
    }
    return false;
}

int main(){

    FAST_IO;    

    ll t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int x;
        cin >> x;

        vector<vector<int> > blocked(n + 1, vector<int>(m + 1, 0));
        vector<vector<int> > visited(n + 1, vector<int>(m + 1, 0));
        vector<vector<int> > dist(n + 1, vector<int>(m + 1, -1));
        int a, b;
        queue<pair<int, pair<int, int> > > q;
        for (int i = 0; i < x; ++i) {
            cin >> a >> b;
            q.push({0, {a, b}});
            dist[a][b] = 0;
            visited[a][b] = 1;
        }

        int y;
        cin >> y;
        for (int i = 0; i < y; ++i) {
            cin >> a >> b;
            blocked[a][b] = 1;
        }

        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            int d = fr.first;
            int xc = fr.second.first;
            int yc = fr.second.second;
            dist[xc][yc] = d;
            for (int k = 0; k < 4; ++k) {
                int nx = xc + dx[k];
                int ny = yc + dy[k];
                if (isSafe(nx, ny, n, m) && !blocked[nx][ny] && !visited[nx][ny]) {
                    q.push({d + 1, {nx, ny}});
                    visited[nx][ny] = 1;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (blocked[i][j]) {
                    cout << "X ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}