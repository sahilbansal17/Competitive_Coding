#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 998244353LL;
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

vector <int> parent(MAX, 0);
vector <int> leafs;
vector <int> adj_list[MAX];
ll bfs_distances[3010][3010];

void calculate_bfs_distances(int n) {
    
    for (int i = 1; i <= n; i ++) {
        vector <bool> visited(n + 1, 0);
        queue <pair<int, int>> q;
        q.push({i, 1});
        while (!q.empty()) {
            pair<int, int> top = q.front();
            int head = top.first;
            int label = top.second;
            for (int j = 0; j < adj_list[head].size(); j ++) {
                int next = adj_list[head][j];
                if (!visited[next]) {
                    q.push({next, label + 1});
                    bfs_distances[i][next] = label;
                }
            }
            visited[head] = 1;
            q.pop();
        }
    }

}

// find depth of a node in the parent representation
/*
int depth(int node) {
    int res = -1;
    while (node != -1) {
        res ++;
        node = parent[node];
    }
    return res;
}
*/

// find distance between two leaves

/*
int distance(int leaf1, int leaf2) {
    int d1 = depth(leaf1);
    int d2 = depth(leaf2);

    int diff = d1 - d2;
    int res = 0; // distance between them

    // leaf1 should have higher depth, WLOG
    if (d1 < d2) {
        swap(leaf1, leaf2);
        swap(d1, d2);
        diff = d1 - d2;
    }

    // make their depths same
    while (diff --) {
        leaf1 = parent[leaf1];
        res ++;
    }

    // move the one level up each time, till they become equal
    while (leaf1 != -1 && leaf2 != -1) {
        if (leaf1 == leaf2) {
            return res;
        }
        leaf1 = parent[leaf1];
        leaf2 = parent[leaf2];
        res += 2;
    }

    return res;
}
*/

// prefix_distances[i][j] represents sum of distance 
// of leaf i to all the leafs: i + 1, i + 2, ..., j
vector <vector <ll> > preprocess_distances() {
    int count_leafs = leafs.size();
    vector < vector <ll> > prefix_distances(count_leafs, vector <ll> (count_leafs, 0));

    for (int i = 0; i < count_leafs; i ++) {
        int leaf1 = leafs[i];
        for (int j = i + 1; j < count_leafs; j ++) {
            // ll separation = distance(leaf1, leafs[j]);
            ll separation = bfs_distances[leaf1][leafs[j]];
            prefix_distances[i][j] = prefix_distances[i][j - 1] + separation;
        }
    }
    return prefix_distances;
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

    parent[1] = -1;
    vector <bool> marked(n + 1, 0);
    marked[1] = true;
    for (int i = 2; i <= n; i ++) {
        cin >> parent[i];
        marked[parent[i]] = true;
        adj_list[parent[i]].push_back(i);
        adj_list[i].push_back(parent[i]);
    }    

    // find the leafs in the graph
    for (int i = 1; i <= n; i ++) {
        if (!marked[i]) {
            leafs.push_back(i);
        }
    }

    calculate_bfs_distances(n);

    /*/
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cerr << bfs_distances[i][j] << " ";
        }
        cerr << endl;
    }
    //*/

    // perform the queries
    ll ans = 0, l = 0, r = 0, count_leafs;
    count_leafs = leafs.size();

    vector <vector <ll> > prefix_leaves, column_add;
    prefix_leaves = preprocess_distances();
    column_add = prefix_leaves;

    // vector <ll> all_leaves(count_leafs, 0);
    for (int i = 0; i < count_leafs; i ++) {
        for (int j = 0; j < count_leafs; j ++) {
            // cerr << prefix_leaves[i][j] << " ";
            // all_leaves[j] += prefix_leaves[i][j];
            column_add[j][i] = prefix_leaves[j][i];
            if (j - 1 >= 0)
                column_add[j][i] += column_add[j - 1][i];
        }
        // cerr << endl;
    }

    for (int i = 0; i < count_leafs; i ++) {
        for (int j = 0; j < count_leafs; j ++) {
            // cerr << column_add[i][j] << " ";
        }
        // cerr << endl;
    }
    // for (int i = 0; i < count_leafs; i ++) {
    //     cerr << all_leaves[i] << " ";
    // }
    // cerr << endl;

    while (q --) {
        cin >> l >> r;
        l = l ^ ans;
        r = r ^ ans;    

        ll numerator = 0; // total distance between every pairs
        ll denominator = 0; // no of pairs
        // find expected distance between any 2 leaves in [L, R]
        
        // index of the left leaf having label in [L, R]
        int left_leaf = lower_bound(leafs.begin(), leafs.end(), l) - leafs.begin();

        // index of the right leaf having label in [L, R]
        int right_leaf = upper_bound(leafs.begin(), leafs.end(), r) - leafs.begin() - 1;

        // for (int i = left_leaf; i < right_leaf; i ++) {
        //     numerator += prefix_leaves[i][right_leaf];
        //     numerator %= MOD;
        //     denominator += right_leaf - i;
        // }

        // cerr << left_leaf << " " << right_leaf << endl;

        // numerator += column_add[right_leaf][right_leaf];
        // numerator -= column_add[left_leaf][right_leaf];
        // numerator %= MOD;
        // denominator = ((right_leaf - left_leaf)*(right_leaf - left_leaf + 1))/2;

        ll t1 = column_add[right_leaf][right_leaf];
        if (left_leaf - 1 >= 0) 
            t1 -= column_add[left_leaf - 1][right_leaf];
        ll t2 = ((right_leaf - left_leaf) * (right_leaf - left_leaf + 1))/2;

        // cerr << t1 << " " << t2 << endl;

        t1 %= MOD;
        numerator = t1;
        denominator = t2;

        if (numerator == 0) {
            ans = 0;
            cout << 0 << endl;
            continue;
        }

        ll d = gcd(numerator, denominator);
        if (d != 0) {
            numerator /= d;
            denominator /= d;
        }

        ll den_inverse = power(1ll*denominator, MOD - 2);

        ans = numerator;
        ans *= den_inverse;
        ans %= MOD;
        cout << ans << endl;

        // cerr << numerator << " " << denominator << endl;
    }

    // cerr << depth(6) << endl;
    // cerr << distance(6, 9) << endl;

    return 0;
}