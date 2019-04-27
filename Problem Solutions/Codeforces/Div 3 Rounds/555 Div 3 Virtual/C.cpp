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
 
    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif
    FAST_IO;

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    bool done = 0;
    string res;
    int count = 0;

    int cur_max = min(a[0], a[n - 1]);

    while (!done && left <= right) {
        int left_diff = a[left] - cur_max;
        int right_diff = a[right] - cur_max;
        if (left_diff < 0 && right_diff < 0) {
            done = 1;
        }
        else {
            if ((left_diff >= 0 && left_diff <= right_diff) || right_diff < 0) {
                res += 'L';
                cur_max = a[left];
                left ++;
                count ++;
            }
            else if ((right_diff >= 0 && right_diff < left_diff) || left_diff < 0) {
                res += 'R';
                cur_max = a[right];
                right --;
                count ++;
            }
        }
    }
    cout << count << endl << res << endl;
    return 0;
}