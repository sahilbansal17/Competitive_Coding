#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
vector<int> adj[MAX], adj2[MAX];

bool my_cmp(int a, int b) {
    if (adj[a].size() == adj[b].size()) {
        return a < b;
    } else {
        return adj[a].size() > adj[b].size();
    }
}

bool my_cmp_2(int a, int b) {
    if (adj2[a].size() == adj2[b].size()) {
        return a < b;
    } else {
        return adj2[a].size() > adj2[b].size();
    }
}

bool visit_cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void dfs(int cur, int p, vector<int>& par) {
    par[cur] = p + 1;
    for (auto next: adj[cur]) {
        if (par[next] == -1) {
            dfs(next, cur, par);
        }
    }
}

bool verify(vector<int>& par) {
    int n = par.size();
    unordered_map<int, int> deg;
    for (int i = 0; i < n; ++i) {
        deg[i] = 0;
        adj2[i].clear();
    }
    
    for (int i = 0; i < n; ++i) {
        int cur = par[i];
        cur = cur - 1;
        while (cur != -1) {
            adj2[i].push_back(cur);
            ++deg[i];
            adj2[cur].push_back(i);
            ++deg[cur];
            cur = par[cur] - 1;
        }
    }

    vector<pair<int, int> > visit_order;
    for (auto mp: deg) {
        visit_order.push_back({mp.second, mp.first});
    }
    sort(visit_order.begin(), visit_order.end(), visit_cmp);

    for (int i = 0; i < n; ++i) {
        sort(adj2[i].begin(), adj2[i].end(), my_cmp_2);
    }

    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        sort(adj2[i].begin(), adj2[i].end());
        if (adj[i] != adj2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    unordered_map<int, int> deg;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int u, v;
        for (int i = 0; i < n; ++i) {
            deg[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++deg[u];
            ++deg[v];
        }

        vector<pair<int, int> > visit_order;
        for (auto mp: deg) {
            visit_order.push_back({mp.second, mp.first});
        }
        sort(visit_order.begin(), visit_order.end(), visit_cmp);

        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end(), my_cmp);
        }

        vector<int> par(n, -1);
        int comp = 0;
        for (int i = 0; i < n; ++i) {
            int cur = visit_order[i].second;
            if (par[cur] == -1) {
                ++comp;
                dfs(cur, -1, par);
            }
        }
        if (comp > 1) {
            cout << "NO" << endl;
        } else {
            if (verify(par)) {
                cout << "YES" << endl;
                for (int i = 0; i < n; ++i) {
                    cout << par[i] << " ";
                }
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        deg.clear();
    }

    return 0;
}