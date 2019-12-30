#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 510;
int main() {
    FAST_IO;
    
    int r, c;
    cin >> r >> c;

    vector<vector<int> > res(MAX, vector<int> (MAX, 0));
    if (r == 1 && c == 1) {
        cout << "0" << endl;
    } else {
        int mag = r + c;

        int val = min(r, c) + 1;
        if (min(r, c) == r) {
            for (int i = 0; i < c; ++i) {
                for (int j = 0; j < r; ++j) {
                    res[j][i] = val*(j + 1);
                }
                ++val;
            }
        } else {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    res[i][j] = val*(j + 1);
                }
                ++val;
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}