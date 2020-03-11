#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

int main() {

    FAST_IO;
    
    int n;
    cin >> n;

    vector<ll> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    vector<int> adj[n];
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<int, int> > q;
    q.push({0, 0});

    map<int, vector<int> > levels;
    vector<int> dist(n, 0);
    vector<int> vis(n, 0);
    levels[0].push_back(0);
    dist[0] = 0;
    int max_dist = 0;
    while (!q.empty()) {
        auto fr = q.front();
        int node = fr.first;
        int c_dist = fr.second;
        vis[node] = 1;
        q.pop();
        for (auto next: adj[node]) {
            if (!vis[next]) {
                q.push({next, c_dist + 1});
                levels[c_dist + 1].push_back(next);
                vis[next] = 1;
                dist[next] = c_dist + 1;
                if (c_dist + 1 > max_dist) {
                    max_dist = c_dist + 1;
                }
            }
        }
    }

    map<int, multiset<ll> > values;
    map<ll, set<int>> inverse_val;
    for (int i = 0; i <= max_dist; ++i) {
        for (auto node: levels[i]) {
            values[i].insert(val[node]);
            inverse_val[val[node]].insert(node);
        }
    }

    int qr;
    cin >> qr;

    int type;
    ll x, y;
    while (qr--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            --x;
            values[dist[x]].erase(val[x]);
            inverse_val[val[x]].erase(x);
            values[dist[x]].insert(y);
            inverse_val[y].insert(x);
            val[x] = y;
        } else {
            cin >> x;
            
            int check = -1;
            for (int i = 0; i <= max_dist; ++i) {
                if (*values[i].rbegin() > x) {
                    check = i;
                    break;
                }
            }

            if (check == -1) {
                cout << "-1" << endl;
                continue;
            }
            int res = INT_MAX;
            auto itr = values[check].upper_bound(x);
            ll check_val = *itr;
            
            for (auto node: inverse_val[check_val]) {
                if (dist[node] == check && node < res) {
                    res = node;
                }
            }

            // for (auto node: levels[check]) {
            //     if (val[node] > x && val[node] < check_val) {
            //         res = node;
            //         check_val = val[node];
            //     } else if (val[node] > x && val[node] == check_val && node < res) {
            //         res = node;
            //     }
            // }
            cout << res + 1 << endl;
        }
    }
    
    return 0;
}