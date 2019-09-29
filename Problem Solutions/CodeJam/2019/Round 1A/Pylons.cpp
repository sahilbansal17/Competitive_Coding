// works for the small case

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 22LL;

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

bool visited[MAX][MAX];
// pair <int, int> nxt[MAX][MAX];
vector < pair <int, int> > res_p;
bool solve (int x, int y, int r, int c) {
    visited[x][y] = true;
    bool res;

    int count = 0;
    for (int i = 0; i < r; i ++) {
        if (i == x) {
            continue;
        }
        for (int j = 0; j < c; j ++) {
            if (j == y) {
                continue;
            }
            if (x - y == i - j) {
                continue;
            }
            if (x + y == i + j) {
                continue;
            }
            if (!visited[i][j]) {
                count ++;
                res = solve (i, j, r, c);
                if (res == 1) {
                    // nxt[x][y] = {r, c};
                    break;
                }
                else {
                    visited[i][j] = false;
                }
            }
        }
        if (res == 1) {
            break;
        }
    }

    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (!visited[i][j]) {
                return 0;
            }
        }
    }

    // if (count == 0) {
    //     nxt[x][y] = {-1, -1};
    // }
    // cerr << x + 1 << " " << y + 1 << endl;
    res_p.push_back({x + 1, y + 1});
    return 1;
}

int main(){

    FAST_IO;    

    int t;
    cin >> t;

    int r, c;
    for (int i = 0; i < t; i ++) {
        cin >> r >> c;
        bool st = false;
        int x, y;
        for (int j = 0; j < r; j ++) {
            for (int k = 0; k < c; k ++) {
                for (int x = 0; x < r; x ++) {
                    for (int y = 0; y < c; y ++) {
                        visited[x][y] = false;
                    }
                }
                st = solve(j, k, r, c);
                if (st) {
                    x = j;
                    y = k;
                    break;
                }
            }
            if (st) {
                break;
            }
        }     
        if (st) {

            cout << "Case #" << i + 1 << ": " << "POSSIBLE" << endl;
            // while(nxt[x][y].first != -1 && nxt[x][y].second != -1) {
            //     cout << x << " " << y << endl;
            //     x = nxt[x][y].first;
            //     y = nxt[x][y].second;
            // }
            reverse(res_p.begin(), res_p.end());
            for (int i = 0; i < r*c; i ++) {
                cout << res_p[i].first << " " << res_p[i].second << endl;
            }
            res_p.clear();
        }
        else {
            cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}