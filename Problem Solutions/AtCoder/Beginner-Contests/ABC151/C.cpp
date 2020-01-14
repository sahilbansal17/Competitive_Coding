#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;

    int n, m;
    cin >> n >> m;

    int p;
    string st;
    vector<int> cnt(n, 0);
    vector<int> done(n, 0);
    
    int cnt_dn = 0;
    int cnt_pn = 0;
    for (int i = 0; i < m; ++i) {
        cin >> p >> st;
        --p;
        if (st == "WA" && !done[p]) {
            ++cnt[p];
            continue;
        } else if (st == "AC" && !done[p]) {
            done[p] = 1;
            cnt_pn += cnt[p];
            ++cnt_dn;
        }
    }
    cout << cnt_dn << " " << cnt_pn << endl;
    return 0;
}