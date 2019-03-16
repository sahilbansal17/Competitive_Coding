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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n, k, x;
    cin >> n >> k;

    string s;
    vector <int> open(n + 1, 0); 

    int count = 0;
    for (int i = 0; i < k; i ++) {
        cin >> s;
        if (s == "CLICK") {
            cin >> x;
            if (!open[x]) {
                open[x] = 1;
                count ++;
            }
            else {
                // close the tweet
                open[x] = 0;
                count --;
            }
        }
        else {
            count = 0;
            // close all the tweets
            for (int j = 1; j <= n; j ++) {
                open[j] = 0;
            }
        }
        cout << count << endl;
    }

    return 0;
}