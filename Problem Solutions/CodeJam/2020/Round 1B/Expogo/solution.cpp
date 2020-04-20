#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

void solve(int case_no) {

    int x, y;
    cin >> x >> y;
    bool possible = true;
    vector<char> directions;
    if ((abs(x) + abs(y)) % 2 == 0) {
        possible = false;
    } else {
        while (x && y) {
            if (x & 1) {
                y = y/2; // next step's y (rescaling)
                int x1 = (x - 1)/2; // move E
                int x2 = (x + 1)/2; // move W
                if (y & 1) {
                    // choose even x
                    if (x1 & 1) {
                        // x2
                        directions.push_back('W');
                        x = x2;
                    } else {
                        // x1
                        directions.push_back('E');
                        x = x1;
                    }
                } else {
                    // choose odd x
                    if (x1 & 1) {
                        // x1
                        directions.push_back('E');
                        x = x1;
                    } else {
                        // x2
                        directions.push_back('W');
                        x = x2;
                    }
                }
            } else {
                x = x/2; // next step's x (rescaling)
                int y1 = (y - 1)/2; // N
                int y2 = (y + 1)/2; // S
                if (x & 1) {
                    // choose even y
                    if (y1 & 1) {
                        // y2
                        directions.push_back('S');
                        y = y2;
                    } else {
                        // y1
                        directions.push_back('N');
                        y = y1;
                    }
                } else {
                    // choose odd y
                    if (y1 & 1) {
                        // y1
                        directions.push_back('N');
                        y = y1;
                    } else {
                        // y2
                        directions.push_back('S');
                        y = y2;
                    }
                }
            }
        }
        while (x) {
            int x1 = (x - 1)/2;
            int x2 = (x + 1)/2;
            if (x1 == 0) {
                directions.push_back('E');
                break;
            } else if (x2 == 0) {
                directions.push_back('W');
                break;
            } else if (x1 & 1) {
                x = x1;
                directions.push_back('E');
            } else {
                x = x2;
                directions.push_back('W');
            }
        }
        while (y) {
            int y1 = (y - 1)/2;
            int y2 = (y + 1)/2;
            if (y1 == 0) {
                directions.push_back('N');
                break;
            } else if (y2 == 0) {
                directions.push_back('S');
                break;
            } else if (y1 & 1) {
                y = y1;
                directions.push_back('N');
            } else {
                y = y2;
                directions.push_back('S');
            }
        }
    }
    cout << "Case #" << case_no << ": ";
    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto dir: directions) {
            cout << dir;
        }
        cout << endl;
    }
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