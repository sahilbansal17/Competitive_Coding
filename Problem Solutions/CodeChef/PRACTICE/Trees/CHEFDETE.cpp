#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;

    vector<int> marked(n + 1, 0);
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        marked[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!marked[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main () {
    FAST_IO;

    solve();
    return 0;
}