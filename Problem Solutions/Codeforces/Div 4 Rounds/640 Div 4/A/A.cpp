#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    int cp = n;
    vector<int> dig;
    int ct = 0;
    int zero = 0;
    while (n) {
        dig.push_back(n % 10);
        if (n % 10 == 0) {
            ++zero;
        }
        n /= 10;
        ++ct;
    }

    cout << ct - zero << endl;
    for (int i = ct - 1; i >= 0; --i) {
        if (dig[i]) {
            cout << pow(10, i) * dig[i] << " ";
        }
    }
    cout << endl;
 
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}