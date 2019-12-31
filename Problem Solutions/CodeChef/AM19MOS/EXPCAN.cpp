#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 1010;
double stored[MAX][MAX];

double solve(int st, int en, vector<ll>& a) {
    if (st > en) {
        return 0;
    } else if (st == en) {
        return a[st];
    }
    if (abs(stored[st][en] + 1) > 1e-9) {
        return stored[st][en];
    }
    double sum = 0;
    sum += 0.25*(a[st] + solve(st + 2, en, a));
    sum += 0.25*(a[en] + solve(st, en - 2, a));
    sum += 0.25*(a[st] + solve(st + 1, en - 1, a));
    sum += 0.25*(a[en] + solve(st + 1, en - 1, a));
    return stored[st][en] = sum;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        memset(stored, -1.0, sizeof(stored));
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        double res = solve(0, n - 1, a);
        cout << fixed << setprecision(9);
        cout << res << endl;
    }

    return 0;
}