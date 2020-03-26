#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<char> s1(n), s2(n);
        bool one_found = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (!one_found) {
                    s1[i] = '0';
                    s2[i] = '1';
                    one_found = true;
                } else {
                    s1[i] = '1';
                    s2[i] = '0';
                }
            } else if (s[i] == '2') {
                if (!one_found) {
                    s1[i] = '1';
                    s2[i] = '1';
                } else {
                    s1[i] = '2';
                    s2[i] = '0';
                }
            } else if (s[i] == '0') {
                s1[i] = '0';
                s2[i] = '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << s1[i];
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << s2[i];
        }
        cout << endl;
    }

    return 0;
}