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

bool my_fun(pair <int, int> p1, pair <int, int> p2) {
    return p1.second < p2.second;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t;
    cin >> t;

    int n, id, child_id;
    for (int i = 0; i < t; i ++) {
        cin >> n;

        int id_sum = 0, child_id_sum = 0;
        for (int j = 0; j < n; j ++) {
            cin >> id >> child_id;
            id_sum += id;
            child_id_sum += child_id;
        }

        cout << id_sum - child_id_sum << endl;
    }
    
    return 0;
}