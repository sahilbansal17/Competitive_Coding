#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    string s;
    cin >> s;

    int cw = 0, cb = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            ++cw;
        } else {
            ++cb;
        }
    }
    if ((cw & 1) && (cb & 1)) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> res;
    int i = 0;
    if (cw & 1) {
        // all whites case
        bool allWhite = true;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'B') {
                allWhite = false;
            }
        }
        if (allWhite) {
            cout << "0" << endl;
            return 0;
        }
        while (i < n - 1) {
            if (s[i] == 'B' && s[i + 1] == 'B') {
                s[i] = 'W';
                s[i + 1] = 'W';
                res.push_back(i);
                i += 2;
            } else if (s[i] == 'B' && s[i + 1] == 'W') {
                swap(s[i], s[i + 1]);
                res.push_back(i);
                ++i;
            } else if (s[i] == 'W') {
                ++i;
            }
        }
    } else {
        // all black case
        bool allBlack = true;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'W') {
                allBlack = false;
            }
        }
        if (allBlack) {
            cout << "0" << endl;
            return 0;
        }
        while (i < n - 1) {
            if (s[i] == 'W' && s[i + 1] == 'W') {
                res.push_back(i);
                s[i] = 'B';
                s[i + 1] = 'B';
                i += 2;
            } else if (s[i] == 'W' && s[i + 1] == 'B') {
                swap(s[i], s[i + 1]);
                res.push_back(i);
                ++i;
            } else if (s[i] == 'B') {
                ++i;
            }
        }
    }
    bool allSame = true;
    char theOnlySameCharacter = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] != theOnlySameCharacter) {
            allSame = false;
            break;
        }
    }
    // assert(allSame, true);
    cout << res.size() << endl;
    for (auto x: res) {
        cout << 1 + x << " ";
    }
    cout << endl;
    return 0;
}