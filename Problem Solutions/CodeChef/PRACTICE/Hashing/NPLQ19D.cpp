#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main () {
    FAST_IO;

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int l = s.length();
        int vis[26] = {0};
        for (int i = 0; i < l; ++i) {
            if (!vis[s[i] - 'a']) {
                cout << s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        cout << endl;
    }
    return 0;
}