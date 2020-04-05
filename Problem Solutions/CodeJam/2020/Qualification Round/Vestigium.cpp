#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

void solve(int case_no) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    int trace = 0;
    int row_count = 0;
    int val;
    for (int row = 0; row < n; ++row) {
        vector<int> done(n + 1, 0);
        bool row_repeat = false;
        for (int col = 0; col < n; ++col) {
            cin >> val;
            matrix[row][col] = val;
            if (row == col) {
                trace += val;
            }
            if (done[val]) {
                row_repeat = true;
            }
            done[val] = 1;
        }
        if (row_repeat) {
            ++row_count;
        }
    }
    int col_count = 0;
    for (int col = 0; col < n; ++col) {
        vector<int> done(n + 1, 0);
        bool col_repeat = false;
        for (int row = 0; row < n; ++row) {
            val = matrix[row][col];
            if (done[val]) {
                col_repeat = true;
            }
            done[val] = 1;
        }
        if (col_repeat) {
            ++col_count;
        }
    }
    cout << "Case #" << case_no << ": " << trace << " " << row_count << " " << col_count << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int id = 1; id <= t; ++id) {
        solve(id);
    }
    
    return 0;
}