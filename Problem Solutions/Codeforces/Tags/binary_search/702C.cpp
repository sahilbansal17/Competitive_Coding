#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define MULTIPLE_TESTS 1
typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
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

void solve_with_set() {
    int n, m;
    cin >> n >> m;

    vector<ll> cities(n);
    vector<ll> towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    set<ll> tower_set(towers.begin(), towers.end());
    ll max_dist = 0;

    for (ll city : cities) {
        auto it = tower_set.lower_bound(city);
        ll dist = LLONG_MAX;

        if (it != tower_set.end()) {
            dist = *it - city;
        }
        if (it != tower_set.begin()) {
            --it;
            dist = min(dist, city - *it);
        }
        max_dist = max(max_dist, dist);
    }

    cout << max_dist << endl;
}

void solve_with_two_pointers() {
    int n, m;
    cin >> n >> m;

    vector<ll> cities(n);
    vector<ll> towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    ll max_dist = 0;
    int tower_idx = 0;

    for (int city_idx = 0; city_idx < n; city_idx++) {
        ll city = cities[city_idx];
        while (tower_idx < m - 1 && abs(towers[tower_idx] - city) >= abs(towers[tower_idx + 1] - city)) {
            tower_idx++;
        }
        ll dist = abs(towers[tower_idx] - city);
        max_dist = max(max_dist, dist);
    }

    cout << max_dist << endl;
}

void solve() {
    solve_with_two_pointers();
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;

    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }

    return 0;
}