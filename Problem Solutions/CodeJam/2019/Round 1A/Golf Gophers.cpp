// need to fix, for small case

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

    FAST_IO;    

    int t, n, m;
    cin >> t >> n >> m;

    for (int i = 0; i < t; i ++) {

        int n = 18;
        int a[20];
        int count = 0, maxcount = 0;
        int st;
        bool wr = 0, done = 0;
        int quer = 1;
        
            count = 0;
            // output 18 numbers
            for (int j = 0; j < 18; j ++) {
                if (j == 17) 
                    cout << n << endl;
                else {
                    cout << n << " ";
                }
            }
            fflush(stdout);

            // read 18 numbers, -1 if invalid data sent
            for (int j = 0; j < 18; j ++) {
                cin >> a[j];
                if (a[0] == -1) {
                    wr = 1;
                    break;
                }
                count += a[j];
                if (count > maxcount) {
                    maxcount = count;
                }
            }

            if (wr == 1) {
                break;
            }

          

        // print g, guess for the no of gophers, 1 if correct, -1 ow
        cout << maxcount << endl;
        fflush(stdout);

        cin >> st;
        if (st == -1) {
            wr = 1;
            break;
        }
        else if (st == 1) {
            done = 1;
            continue;
        }   
    }

    return 0;
}