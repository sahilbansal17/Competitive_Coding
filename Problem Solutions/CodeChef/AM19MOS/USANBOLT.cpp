#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        double f, t, d, b;
        cin >> f >> d >> t >> b;

        double tiger = sqrt(2*(f + d)/t);
        double bolt = f/b;
        // cout << tiger << " " << bolt << endl;
        if (tiger - bolt > 1e-6) {
            cout << "Bolt" << endl;
        } else {
            cout << "Tiger" << endl;
        }
    }

    return 0;
}