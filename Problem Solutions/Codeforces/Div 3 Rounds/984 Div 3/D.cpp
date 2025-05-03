#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
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

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;

    ll t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int ans = 0;
        vector<string> mat(n);
        for (int i = 0; i < n; ++i) {
            cin >> mat[i];
        }

        int top_row = 0, top_col = 0, bot_row = n - 1, bot_col = m - 1;

        while (top_row <= bot_row && top_col <= bot_col) {
            vector<char> cur;
            // left->right
            for (int i = top_col; i <= bot_col; ++i) {
                cur.push_back(mat[top_row][i]);
            }
            ++top_row;
            // top->down
            for (int i = top_row; i <= bot_row; ++i) {
                cur.push_back(mat[i][bot_col]);
            }
            --bot_col;
            // right -> left
            for (int i = bot_col; i >= top_col; --i) {
                cur.push_back(mat[bot_row][i]);
            }
            --bot_row;
            // down->top
            for (int i = bot_row; i >= top_row; --i) {
                cur.push_back(mat[i][top_col]);
            }
            ++top_col;

            int k = cur.size();
            unordered_set<int> visited;
            for (int i = 0; i < k; ++i) {
                char a = cur[i];
                int nxt = (i + 1) % k;
                char b = cur[nxt];
                nxt = (nxt + 1) % k;
                char c = cur[nxt];
                nxt = (nxt + 1) % k;
                char d = cur[nxt];

                int idx = -1;
                if (a == '1' && b == '5' && c == '4' && d == '3') {
                    idx = i;
                }
                // if (a == '5' && b == '4' && c == '3' && d == '1') {
                //     idx = (i + 3) % k;
                // }
                // if (a == '4' && b == '3' && c == '1' && d == '5') {
                //     idx = (i + 2) % k;
                // }
                // if (a == '3' && b == '1' && c == '5' && d == '4') {
                //     idx = (i + 1) % k;
                // }

                if (idx != -1) {
                    // cerr << idx << endl;
                    if (visited.find(idx) == visited.end()) {
                        ++ans;
                        visited.insert(idx);
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
