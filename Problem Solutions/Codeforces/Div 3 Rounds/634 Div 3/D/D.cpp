#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    vector<vector<char>> sudoku(9, vector<char>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
        }
    }

    sudoku[0][0] = sudoku[0][1];
    sudoku[3][1] = sudoku[3][2];
    sudoku[6][2] = sudoku[6][0];

    sudoku[1][3] = sudoku[1][4];
    sudoku[4][4] = sudoku[4][5];
    sudoku[7][5] = sudoku[7][3];

    sudoku[2][6] = sudoku[2][7];
    sudoku[5][7] = sudoku[5][8];
    sudoku[8][8] = sudoku[8][6];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}