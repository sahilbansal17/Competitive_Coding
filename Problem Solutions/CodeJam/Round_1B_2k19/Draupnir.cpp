#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

int main(){ 

    // #ifndef ONLINE_JUDGE
    // freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    // freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    // freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    // #endif

    FAST_IO;

    int t, w;
    cin >> t >> w;

    for (int i = 0; i < t; i ++) {
        // W max queries

        ll b[6], x[6];
        bool wr = false;
        for (int j = 0; j < 6; j ++) {
            cout << j + 1 << endl;
            cout.flush();
            cin >> b[j];
            if (b[j] == -1) {
                wr = 1;
                break;
            }
        }
        if (wr == 1) {
            break;
        }

        // calculate result
        x[0] = 4*(b[0] - b[1]) - 2*b[2] + b[5];
        x[0] /= 40;
        x[1] = 24*(b[1] - b[0]) + 2*b[2] - b[5];
        x[1] /= 20;
        x[2] = -4*b[0] -6*b[1] + 12*b[2] - b[5];
        x[2] /= 10;
        x[3] = 16*(b[0] - b[1]) - 8*b[2] + 10*b[3] - b[5];
        x[3] /= 10;
        x[4] = 8*(b[1] - b[0]) + 4*b[2] - 5*b[3] + 5*b[4] - 2*b[5];
        x[4] /= 5; 
        x[5] = 12*b[0] - 2*b[1] - 6*b[2] - 5*b[4] + 3*b[5];
        x[5] /= 5;

        // output 6 values 
        for (int j = 0; j < 6; j ++) {
            cout << x[j] << " ";
        }
        cout << endl;
        cout.flush();

        int status;
        cin >> status;

        if (status == -1) {
            break;
        }
    }

    return 0;
}