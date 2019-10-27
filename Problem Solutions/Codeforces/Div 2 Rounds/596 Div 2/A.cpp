#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int x, y;
    cin >> x >> y;

    if (y == x + 1) {
        cout << x << "9 ";
        cout << y << "0" << endl;
    } else if (y == x) {
        cout << x << "1 ";
        cout << y << "2" << endl;
    } else if (x == 9 && y == 1) {
        cout << 99 << " " << 100 << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}