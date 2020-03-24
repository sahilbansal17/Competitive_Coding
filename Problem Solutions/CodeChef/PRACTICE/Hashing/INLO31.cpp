#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main () {
    FAST_IO;

    int n[5];
    for (int i = 0; i < 5; ++i) {
        cin >> n[i];
    }

    unordered_map<int, int> cnt;
    unordered_set<int> done;
    int id;
    int res = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            cin >> id;
            ++cnt[id];
            if (cnt[id] > 2 && done.find(id) == done.end()) {
                ++res;
                done.insert(id);
            }
        }
    }
    cout << res << endl;
    return 0;
}