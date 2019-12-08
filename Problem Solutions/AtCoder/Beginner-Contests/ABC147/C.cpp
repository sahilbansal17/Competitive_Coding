#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int result = 0;
void solve(int i, int n, map<int, vector<pair<int, int>>>& test, vector<int>& marked) {
    if (i == n + 1) {
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (marked[i] == 1) {
                ++cur;
            }
        }
        if (cur > result) {
            result = cur;
        }
        return;
    }
    if (marked[i] == 0) {
        // honest
        marked[i] = 1;
        vector<int> copy = marked;

        bool possible = true;
        for (auto t: test[i]) {
            int x = t.first;
            int y = t.second;
            if (y == 1) {
                // honest
                if (marked[x] == 2) {
                    possible = false;
                    // contradiction
                    // return ;
                    break;
                } else {
                    marked[x] = 1;
                }
            } else {
                // unkind
                if (marked[x] == 1) {
                    possible = false;
                    // contradiction
                    // return ;
                    break;
                } else {
                    marked[x] = 2;
                }
            }
        }
        if (possible) {
            solve(i + 1, n, test, marked);
        }
        // unkind
        marked = copy;
        marked[i] = 2; // no need to check testimonies
        solve(i + 1, n, test, marked);
    } else if (marked[i] == 1) {
        bool possible = true;
        for (auto t: test[i]) {
            int x = t.first;
            int y = t.second;
            if (y == 1) {
                // honest
                if (marked[x] == 2) {
                    possible = false;
                    // contradiction
                    return ;
                } else {
                    marked[x] = 1;
                }
            } else {
                // unkind
                if (marked[x] == 1) {
                    possible = false;
                    // contradiction
                    return ;
                } else {
                    marked[x] = 2;
                }
            }
        }
        if (possible) {
            solve(i + 1, n, test, marked);
        }
    } else if (marked[i] == 2) {
        solve(i + 1, n, test, marked);
    }
}

int main() {

    FAST_IO;

    int n;
    cin >> n;

    int count, x, y;
    map<int, vector<pair<int, int> > > testimonies;

    for (int i = 1; i <= n; ++i) {
        cin >> count;
        for (int j = 0; j < count; ++j) {
            cin >> x >> y;
            testimonies[i].push_back({x, y});
        }
    }

    vector<int> marked(n + 1, 0);
    solve(1, n, testimonies, marked);

    cout << result << endl;
    return 0;
}