#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    int r, c;
    while (t--) {
        cin >> r >> c;

        vector<vector<char> > grid(r, vector<char> (c));
        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') {
                    ++cnt;
                }
            }
        }

        /*
         * MORTAL
         * MORTAL
         * MORTAL
         */ 
        if (cnt == 0) {
            cout << "MORTAL" << endl;
            continue;
        }

        /*
         * 0
         * 0
         * 0
         */ 

        if (cnt == r*c) {
            cout << "0" << endl;
            continue;
        }

        // for 1
        bool topRow = true;
        bool lastRow = true;
        bool leftCol = true;
        bool lastCol = true;
        int cntTopRow = 0;
        int cntLastRow = 0;
        int cntLeftCol = 0;
        int cntLastCol = 0;
        for (int i = 0; i < c; ++i) {
            if (grid[0][i] == 'P') {
                topRow = false;
            } else {
                ++cntTopRow;
            }
            if (grid[r - 1][i] == 'P') {
                lastRow = false;
            } else {
                ++cntLastRow;
            }
        }
        for (int i = 0; i < r; ++i) {
            if (grid[i][0] == 'P') {
                leftCol = false;
            } else {
                ++cntLeftCol;
            }
            if (grid[i][c - 1] == 'P') {
                lastCol = false;
            } else {
                ++cntLastCol;
            }
        }

        /*
         * 1
         * 1
         * 1
         */
        if (topRow || lastRow || leftCol || lastCol) {
            cout << "1" << endl;
            continue;
        }

        // for 2
        bool done = false;
        // top row
        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < c; ++i) {
            if (grid[0][i] == 'P') {
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (left == INT_MAX && right == INT_MIN) {
            left = 0;
            right = c - 1;
            // will check if any row contains all A's
        }
        for (int i = 1; i < r; ++i) {
            bool possible = true;
            for (int j = left; j <= right; ++j) {
                if (grid[i][j] == 'P') {
                    possible = false;
                }
            }
            if (possible) {
                done = true;
                break;
            }
        }
        /*
         * 2
         * 2
         * 2
         */
        if (done) {
            cout << "2" << endl;
            continue;
        }

        // bottom row
        left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < c; ++i) {
            if (grid[r - 1][i] == 'P') {
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (left == INT_MAX && right == INT_MIN) {
            left = 0;
            right = c - 1;
            // will check if any row contains all A's
        }
        for (int i = 0; i < r - 1; ++i) {
            bool possible = true;
            for (int j = left; j <= right; ++j) {
                if (grid[i][j] == 'P') {
                    possible = false;
                }
            }
            if (possible) {
                done = true;
                break;
            }
        }
        /*
         * 2
         * 2
         * 2
         */
        if (done) {
            cout << "2" << endl;
            continue;
        }

        // left col
        left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < r; ++i) {
            if (grid[i][0] == 'P') {
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (left == INT_MAX && right == INT_MIN) {
            left = 0;
            right = r - 1;
            // will check if any col contains all A's
        }
        for (int i = 1; i < c; ++i) {
            bool possible = true;
            for (int j = left; j <= right; ++j) {
                if (grid[j][i] == 'P') {
                    possible = false;
                }
            }
            if (possible) {
                done = true;
                break;
            }
        }
        /*
         * 2
         * 2
         * 2
         */
        if (done) {
            cout << "2" << endl;
            continue;
        }

        // rightmost col
        left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < r; ++i) {
            if (grid[i][c - 1] == 'P') {
                left = min(left, i);
                right = max(right, i);
            }
        }
        if (left == INT_MAX && right == INT_MIN) {
            left = 0;
            right = r - 1;
            // will check if any col contains all A's
        }
        for (int i = 0; i < c - 1; ++i) {
            bool possible = true;
            for (int j = left; j <= right; ++j) {
                if (grid[j][i] == 'P') {
                    possible = false;
                }
            }
            if (possible) {
                done = true;
                break;
            }
        }
        /*
         * 2
         * 2
         * 2
         */
        if (done) {
            cout << "2" << endl;
            continue;
        }

        /*
         * 2
         * 2
         * 2
         */
        // if A at any corner, then also 2
        if (grid[0][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[r - 1][c - 1] == 'A') {
            cout << "2" << endl;
            continue;
        }

        // if no cell present in any extreme row or col, then 4
        if (cntTopRow == 0 && cntLastRow == 0 && cntLeftCol == 0 && cntLastCol == 0) {
            cout << "4" << endl;
            continue;
        }

        // other cases
        cout << "3" << endl;
        continue;
    }   

    return 0;
}