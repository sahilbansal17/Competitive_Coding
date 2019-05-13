#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

vector <ll> k(MAX, 0);
vector <ll> b(MAX, 0);
vector <int> adj_list[MAX];

vector <int> shortest_path(int u, int v) {
    vector <int> res;

    queue <int> q;
    q.push(u);

    unordered_map <int, int> parent;
    parent[u] = -1;
    vector <int> visited(MAX, 0);

    while (!q.empty()) {
        int top = q.front();
        for (int next_id = 0; next_id < adj_list[top].size(); next_id ++) {
            int next_node = adj_list[top][next_id];
            if (!visited[next_node]) {
                q.push(next_node);
                parent[next_node] = top;
            }
        }
        visited[top] = true;
        q.pop();
    }

    while (v != -1) {
        res.push_back(v);
        v = parent[v];
    }

    return res;
}

// increase k's on SP from u->v by x
// increase b's on SP from u->v by y
void reform(int u, int v, ll x, ll y) {
    vector <int> sp = shortest_path(u, v);
    for (int i = 0; i < sp.size(); i ++) {
        k[sp[i]] += x;
        b[sp[i]] += y;
    }
}

// find the max quality of toy on SP from u->v
// qual(j, i) = K_i(j) + B_i 
// quality of toy of type j in city i
ll find(int u, int v, ll z) {
    vector <int> sp = shortest_path(u, v);
    ll current_qual = 0, max_qual = LONG_MIN;
    for (int i = 0; i < sp.size(); i ++) {
        int city = sp[i];
        current_qual = z*k[city] + b[city];
        if (current_qual > max_qual) {
            max_qual = current_qual;
        }
    }
    return max_qual;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i ++) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    int u, v;
    for (int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int type;
    ll x, y, z;
    for (int i = 0; i < q; i ++) {
        cin >> type >> u >> v;
        if (type == 1) {
            cin >> x >> y;
            reform(u, v, x, y);
        }
        else {
            cin >> z;
            cout << find(u, v, z) << endl;
        }
    }

    // vector <int> sp = shortest_path(1, 5);
    // for (auto i: sp) {
    //     cerr << i << " ";
    // }
    return 0;
}