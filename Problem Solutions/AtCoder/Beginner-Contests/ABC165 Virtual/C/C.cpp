#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

struct quad {
    int a, b, c, d;
    quad(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
};

vector<quad> constraints;
int compute(vector<int>& arr) {
    int q = constraints.size();
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int a = constraints[i].a; int b = constraints[i].b; 
        int c = constraints[i].c; int d = constraints[i].d;
        --a; --b;
        if (arr[b] - arr[a] == c) {
            ans += d;
        }
    }
    return ans;
}

void checkAll(int cur, int n, int m, vector<int>& a, int &res) {
    if (cur == n) {
        res = max(res, compute(a));
        return;
    }
    int val = 1;
    if (cur - 1 >= 0) {
        val = a[cur - 1];
    }
    for (int next = val; next <= m; ++next) {
        a[cur] = next;
        checkAll(cur + 1, n, m, a, res);
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    int a, b, c, d;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c >> d;
        quad qu(a, b, c, d);
        constraints.push_back(qu);
    }

    int res = 0;
    vector<int> arr(n, 0);
    checkAll(0, n, m, arr, res);
    cout << res << endl;
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}