#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 200010LL;

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

ll cnt[MAX], remaining = 0;
vector < pair <int, int> > offers;

bool possible(ll mid) {
    int day = 1;
    int money = 1;

    ll cnt_copy[MAX], rem_copy = remaining;
    for (int i = 0; i < MAX; i ++) {
        cnt_copy[i] = cnt[i];
    }

    for (int i = 0; i < offers.size(); i ++) {
        int offerd = offers[i].first;
        int offert = offers[i].second;
        if (offerd > mid) {
            break;
        }
        if (offerd == day && money > 0 && cnt_copy[offert] > 0) {
            money --;
            remaining --;
            cnt_copy[offert] --;
        }
        else if (offerd > day) {
            money += offerd - day;
            i --; // consider same offer again
            day = offerd;
        }
    }
    if (money >= 2*remaining) {
        return true;
    }
    int diff = 2*remaining - money;
    remaining = rem_copy;
    int final_day = day + diff;
    if (final_day <= mid) {
        return true;
    }
    return false;
}

int main(){
 
    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif
    FAST_IO;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        cin >> cnt[i];
        remaining += cnt[i];
    }

    int day, type;
    for (int i = 0; i < m; i ++) {
        cin >> day >> type;
        offers.push_back({day, type});
    }
    sort(offers.begin(), offers.end());

    ll low = remaining, high = 2*remaining, mid, ans;
    while (low < high) {
        mid = low + (high - low)/2;

        // cerr << low << " " << high << " " << mid << endl;
        if (possible(mid)) {
            // cerr << "1" << endl << endl;
            high = mid;
            ans = mid;
        }
        else {
            // cerr << "0" << endl << endl;
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}