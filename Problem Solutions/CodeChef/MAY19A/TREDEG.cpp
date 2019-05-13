// solved subtask 1

#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 998244353LL;
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

vector <int> cur;
vector <vector <int> > degree_sequences;
void find_deg_sequence(int n, int i, int sum) {
    if (sum == 2*n - 2 && i == n + 1) {
        degree_sequences.push_back(cur);
        return;
    }
    else if (i == n + 1) {
        return ;
    }
    else if (sum > 2*n - 2) {
        return ;
    }
    for (int deg = 1; deg <= n - 1; deg ++) {
        cur.push_back(deg);
        find_deg_sequence(n, i + 1, sum + deg);
        cur.pop_back();
    }
}

ll factorial[MAX];

ll fact(int n) {
    if (n == 0) {
        return factorial[0] = 1;
    }
    if (factorial[n] != 0) {
        return factorial[n];
    }
    ll res = n * fact(n - 1);
    factorial[n] = res;
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t, n, k;
    cin >> t;

    for (int i = 0; i < MAX; i ++) {
        factorial[i] = 0;
    }

    while (t --) {
        cin >> n >> k;

        // generate all labelled trees with n-vertices
        // find product of degrees of each of the vertices
        // do modular exponentiation to get (P)
        // total no. of trees is also known (Q)
        // P*Q^(-1) % MOD = (P % MOD) * (Q^(-1) % MOD) ) % MOD

        // find all possible degree sequences
        // and the corresponding number of labelled trees for them

        // x1 + x2 + ... + xn = 2n - 2
        find_deg_sequence(n, 1, 0);

        ll P = 0;
        for (int i = 0; i < degree_sequences.size(); i ++) {

            ll cur_product = 1;
            
            // find the count of labelled trees for this value
            ll count = 0;
            count = fact(n - 2);
            vector <int> seq = degree_sequences[i];
            for (int j = 0; j < degree_sequences[i].size(); j ++) {
                // cerr << degree_sequences[i][j] << " ";
                cur_product *= degree_sequences[i][j];
                cur_product %= MOD;

                count /= fact(degree_sequences[i][j] - 1);
            }
            cur_product = power(cur_product, 1ll*k);
            cur_product *= count;
            cur_product %= MOD;

            P += cur_product;
            P %= MOD;
            // cerr << endl;
        }

        // total no. of labelled trees
        ll total = power(1ll*n, 1ll*n - 2);
        // cerr << total << endl;

        ll Q_inverse = power(total, MOD - 2ll);

        ll res = P;
        res *= Q_inverse;
        res %= MOD;

        // cerr << P << " " << Q_inverse << endl;
        cout << res << endl;

        // make sure to clear the previous results
        degree_sequences.clear();
    }

    return 0;
}