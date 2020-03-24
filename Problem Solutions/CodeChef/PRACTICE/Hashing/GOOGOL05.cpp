#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main () {
    FAST_IO;

    int n;
    cin >> n;

    map<string, int> cnt;
    string dept;
    for (int i = 0; i < n; ++i) {
        cin >> dept;
        ++cnt[dept];
    }

    for (auto it: cnt) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}