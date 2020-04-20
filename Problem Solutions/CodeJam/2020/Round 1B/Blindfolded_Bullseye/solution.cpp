#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

void solve(int case_no) {

    // test set 1
    string res;
    for (int x = -5; x <= 5; ++x) {
        for (int y = -5; y <= 5; ++y) {
            cout << x << " " << y << endl;
            cout.flush();
            cin >> res;
            if (res == "CENTER") {
                return;
            }
        }
    }
}

int main() {
    FAST_IO;

    int t, a, b;
    cin >> t >> a >> b;

    for (int id = 1; id <= t; ++id) {
        solve(id);
    }
    
    return 0;
}