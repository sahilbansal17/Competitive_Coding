#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const double PI =  3.141592653589793238;

void solve() {
    double n;
    cin >> n;

    cout << fixed << setprecision(10);
    cout << 1/(tan(PI/(2*n))) << endl;

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