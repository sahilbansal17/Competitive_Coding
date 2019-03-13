#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 300010LL;

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

vector <int> color(MAX), g[MAX], visited(MAX, 0);

int ct[2][MAX];

int dfs (int x, int c) {

    visited[x] = true;

    int res = 0;
    for (int i = 0; i < g[x].size(); i ++) {
        if (!visited[g[x][i]]) {
            res += dfs (g[x][i], c);
        }
    }

    if (color[x] == c) {
        ct[c - 1][x] = res + 1;
        return res + 1;
    }

    ct[c - 1][x] = res;
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n;
    cin >> n;

    int all_red = 0, all_blue = 0;
    for (int i = 0; i < n; i ++) {
        cin >> color[i];
        if (color[i] == 1) {
            all_red ++;
        }
        else if (color[i] == 2) {
            all_blue ++;
        }
    }

    int u, v;
    for (int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    dfs(0, 1); // red
    for (int i = 0; i < n; i ++) {
        visited[i] = false;
    }
    dfs(0, 2); // blue

    int res = 0;

    // for (int i = 0; i < n; i ++) {
    //     cerr << ct[0][i] << " ";
    // }
    // cerr << endl;
    // for (int i = 0; i < n; i ++) {
    //     cerr << ct[1][i] << " ";
    // }

    for (int i = 1; i < n; i ++) {
        if (ct[0][i] == all_red && ct[1][i] == 0) {
            res ++;
        }
        else if (ct[0][i] == 0 && ct[1][i] == all_blue) {
            res ++;
        }
    }

    cout << res << endl;
    return 0;
}