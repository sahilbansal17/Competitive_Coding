#include <iostream>
#include <map>
#include <vector>

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

vector <int> a(MAX);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t, n;
    cin >> t;

    int sum, sum_d, count_pos;
    for (int i = 0; i < t; i ++) {
        cin >> n;

        sum = 0;
        sum_d = 0;
        count_pos = 0;
        for (int j = 0; j < n; j ++) {
            cin >> a[j];
            sum += a[j];
            if (a[j] > 0) {
                count_pos ++;
            }
        }

        if (sum < 100) {
            cout << "NO";
        }
        else {
            // sum >= 100
            sum_d = sum - count_pos;
            if (sum_d < 100) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
        cout << endl;
    }

    
    return 0;
}