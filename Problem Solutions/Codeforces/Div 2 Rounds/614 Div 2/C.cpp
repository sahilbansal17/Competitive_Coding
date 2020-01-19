#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;

int main() {
    FAST_IO;
    int n, q;
    cin >> n >> q;
    int r, c;
    unordered_set<int> unreach;
    int marked[3][MAX];
    memset(marked, 0, sizeof(marked));
    for (int i = 0; i < q; ++i) {
        cin >> r >> c;
        marked[r][c] ^= 1;
        if (marked[r][c]) {
            if (r == 2 && c - 1 >= 1 && marked[1][c - 1]) {
                unreach.insert(c);
            }
            if (r == 1 && c - 1 >= 1 && marked[2][c - 1]) {
                unreach.insert(c);
            }
            if (r == 1 && marked[2][c]) {
                unreach.insert(c);
            }
            if (r == 2 && marked[1][c]) {
                unreach.insert(c);
            }
            if (r == 2 && c + 1 <= n && marked[1][c + 1]) {
                unreach.insert(c + 1);
            }
            if (r == 1 && c + 1 <= n && marked[2][c + 1]) {
                unreach.insert(c + 1);
            }
        } else {
            if (r == 2 && !marked[1][c]) {
                unreach.erase(c);
            }
            if (r == 1 && !marked[2][c]) {
                unreach.erase(c);
            }
            if (r == 1 && c - 1 >= 1 && !marked[1][c - 1]) {
                unreach.erase(c);
            }
            if (r == 2 && c - 1 >= 1 && !marked[2][c - 1]) {
                unreach.erase(c);
            }
            if (r == 1 && c + 1 <= n && !marked[1][c + 1]) {
                unreach.erase(c + 1);
            }
            if (r == 2 && c + 1 <= n && !marked[2][c + 1]) {
                unreach.erase(c + 1);
            }
        }

        if (unreach.size() >= 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        
    }

    return 0;
}