/**
 * References:
 * https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const int MAXN = 2e5 + 10;

// stores smallest prime factor for every number
ll spf[MAXN];
// stores the minimum power of a prime occurring in any factorization
ll min1[MAXN];
// stores the second minimum power of a prime occurring in any factorization
ll min2[MAXN];

// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
void sieve();

// A O(log n) function returning prime factorization
// by dividing by smallest prime factor at every step
// returns the pairs of {prime, its power}
vector<pair<int, int>> getFactorization(int x);

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &a : arr) {
        cin >> a;
    }

    sieve();
    memset(min1, -1, sizeof(min1));
    memset(min2, -1, sizeof(min2));

    vector<int> cnt(MAXN, 0); // count of the numbers in which a particular prime appears in the factorization
    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        vector<pair<int, int>> fact = getFactorization(x); // {prime, its power} pairs
        for (auto ff : fact) {
            int p = ff.first; // prime
            int c = ff.second; // power of prime occurring in factorization

            // update first min and second min for the given power
            if (min1[p] == -1) {
                min1[p] = c;
            } else if (min2[p] == -1) {
                int m = min1[p];
                if (c <= m) {
                    min1[p] = c;
                    min2[p] = m;
                } else {
                    min1[p] = m;
                    min2[p] = c;
                }
            } else {
                int m1 = min1[p];
                int m2 = min2[p];
                if (c <= m1) {
                    min1[p] = c;
                    min2[p] = m1;
                } else if (c <= m2) {
                    min2[p] = m2;
                }
            }
            ++cnt[p];
        }
    }

    ll res = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (cnt[i] == n) { // prime occurring in all the numbers, consider second min power
            res *= pow(1ll * i, min2[i]);
        } else if (cnt[i] == n - 1) { // prime occuring in n - 1 numbers, consider first min power
            res *= pow(1ll * i, min1[i]);
        }
    }
    cout << res << endl;
}


void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

    // marking smallest prime factor for every
    // number to be itself.
    spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
        // marking SPF for all numbers divisible by i
        for (int j = i * i; j < MAXN; j += i)
            // marking spf[j] if it is not
            // previously marked
            if (spf[j] == j) spf[j] = i;
        }
    }
}

// A O(log n) function returning prime factorization
// by dividing by smallest prime factor at every step
// returns the pairs of {prime, its power}
vector<pair<int, int>> getFactorization(int x) {
    vector<pair<int, int>> ret;
    while (x != 1) {
        int cur = spf[x];
        int cnt = 0;
        while (x && spf[x] == cur) {
            ++cnt;
            x = x / spf[x];
        }
        ret.push_back({cur, cnt});
    }
    return ret;
}

int main() {
  FAST_IO;

  int t;
  // cin >> t;
  t = 1;

  while (t--) {
    solve();
  }

  return 0;
}