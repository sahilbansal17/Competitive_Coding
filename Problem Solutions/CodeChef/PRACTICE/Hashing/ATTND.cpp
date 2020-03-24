#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

vector<string> split_first_last(string name) {
    int i = 0;
    int n = name.length();
    while (i < n && name[i] != ' ') {
        ++i;
    }
    return {name.substr(0, i), name.substr(i + 1)};
}
int main () {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // extra, required
        string ss;
        getline(cin, ss);

        string name;
        vector<vector<string>> names(n);
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; ++i) {
            getline(cin, name);
            vector<string> split = split_first_last(name);
            names[i] = split;
            ++cnt[names[i][0]];
        }

        for (int i = 0; i < n; ++i) {
            if (cnt[names[i][0]] > 1) {
                cout << names[i][0] << " " << names[i][1] << endl;
            } else {
                cout << names[i][0] << endl;
            }
        }
    }
    return 0;
}