#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;

    int a[3];
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    if (a[0] + a[1] + a[2] >= 22) {
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }
    
    return 0;
}