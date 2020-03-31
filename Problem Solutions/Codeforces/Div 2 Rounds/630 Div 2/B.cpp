#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<int> primes;
vector<int> is_prime;
void sieve(int bound) {
    is_prime.assign(bound, 1);
    is_prime[2] = 1;
    for (int i = 2; i < bound; ++i) {
        if (!is_prime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i*i; j < bound; j += i) {
            is_prime[j] = 0;
        }
    }
}
int main() {
    FAST_IO;

    int t;
    cin >> t;

    sieve(1010);
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> res(n, -1);
        int cur = 0;
        int done = 0;

        vector<int> col(11, 0);
        int used = 0;
        int cur_col = 0;
        while (done < n) {
            bool new_col = false;
            for (int i = 0; i < n; ++i) {
                if (res[i] == -1 && (a[i] % primes[cur] == 0)) {
                    if (col[cur_col] == 0) {
                        ++used;
                        col[cur_col] = 1;
                    }
                    res[i] = cur_col + 1;
                    ++done;
                    new_col = true;
                }
            }
            cur_col += (new_col) ? 1 : 0;
            ++cur;
        }

        cout << used << endl;
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}