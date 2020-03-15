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

    int u, v;

    vector<int> deg(n, 0);
    vector<pair<pair<int, int>, int>> edges;
    int with_three = -1;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ++deg[u];
        ++deg[v];
        edges.push_back({{u, v}, -1});
        if (deg[u] == 3) {
            with_three = u;
        }
        if (deg[v] == 3) {
            with_three = v;
        }
    }
    
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (edges[i].first.first == with_three || edges[i].first.second == with_three) {
            edges[i].second = cur++;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (edges[i].second == -1) {
            edges[i].second = cur++;
        }
        cout << edges[i].second << endl;
    }
    return 0;
}