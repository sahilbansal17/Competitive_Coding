#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<string> vn, vm;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vn.push_back(s);
    }    
    for (int i = 0; i < m; ++i) {
        cin >> s;
        vm.push_back(s);
    }

    int q;
    cin >> q;
    int x;

    int s1, s2;
    while (q--) {
        cin >> x;

        --x;
        s1 = x % n;
        s2 = x % m;
        cout << vn[s1] + vm[s2] << endl;
    }
    return 0;
}