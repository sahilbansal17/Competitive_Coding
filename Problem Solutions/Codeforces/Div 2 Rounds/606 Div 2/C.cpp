#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int t;
    cin >> t;

    string s;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        int l = s.length();

        vector<int> removed(l + 1, 0);
        vector<int> res;
        int cnt = 0;
        for (int j = 2; j < l; ++j) {
            if (s[j] == 'e') {
                if (s[j - 1] == 'n' && s[j - 2] == 'o' && !removed[j - 2]) {
                    removed[j - 1] = 1; // 'n'
                    res.push_back(j - 1);
                    ++cnt;
                } 
            } else if (!removed[j] && s[j] == 'o') {
                if (s[j - 1] == 'w' && s[j - 2] == 't') {
                    if (j + 1 < l && s[j + 1] == 'n' && j + 2 < l && s[j + 2] == 'e') {
                        removed[j] = 1; // 'o'
                        res.push_back(j);
                        ++cnt;
                    } else {
                        removed[j - 1] = 1; // 'w'
                        res.push_back(j - 1);
                        ++cnt;
                    }
                }
            }
        }
        cout << cnt << endl;
        if (cnt == 0) {
            cout << endl;
        } else {
            for (int j = 0; j < cnt; ++j) {
                cout << res[j] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}