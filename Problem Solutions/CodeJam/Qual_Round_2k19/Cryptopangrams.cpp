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

    int t, n, l;
    cin >> t;

    ll x, d;
    vector <ll> c;
    
    vector <ll> prime_idx;
    ll cur_value;
    set <ll> all_primes;
    ll sorted[26];
    char ch;
    string res;

    ll pr1, pr2, common, start;
    for (int i = 0; i < t; i ++) {
        
        cin >> n >> l;
        for (int j = 0; j < l; j ++) {
            cin >> x;
            c.push_back(x);
        }
        
        d = gcd(c[0], c[1]);
        if (c[0] == c[1]) {
            if ((ll(sqrt(c[0])) * ll(sqrt(c[0]))) == c[0]) {
                pr1 = sqrt(c[0]);
                pr2 = pr1;
                common = pr1;
                prime_idx.push_back(common);
                prime_idx.push_back(common);
                prime_idx.push_back(common);
                
                all_primes.insert(common);
                all_primes.insert(common);
                all_primes.insert(common);
                start = 2;
            }
            else {
                ll fac1, fac2;
                for (fac1 = 2; fac1 <= ll(sqrt(c[0])); fac1 ++) {
                    if (c[0] % fac1 == 0) {
                        fac2 = c[0]/fac1;
                        break;
                    }
                }
                int count_pr1 = 2, count_pr2 = 1;
                ll first, last;
                for (int j = 2; j < l; j ++) {
                    if (c[j] != c[0]) {
                        start = j;
                        if (j & 1) {
                            if (c[j] % fac1 == 0) {
                                first = fac2;
                                last = fac1;
                            }
                            else {
                                first = fac1;
                                last = fac2;
                            }
                        }
                        else {
                            if (c[j] % fac1 == 0) {
                                first = fac1;
                                last = fac1;
                            }
                            else {
                                first = fac2;
                                last = fac2;
                            }
                        }
                        break;
                    }
                    else if (j & 1) {
                        count_pr1 ++;
                    }
                    else {
                        count_pr2 ++;
                    }
                }
                
                pr2 = last;
                if (first == fac1) {
                    while (count_pr1 > 0) {
                        prime_idx.push_back(fac1);
                        if(count_pr2 > 0) {
                            prime_idx.push_back(fac2);
                        }
                        count_pr1 --;
                        count_pr2 --;
                    }
                    if (count_pr2 > 0) {
                        prime_idx.push_back(fac2);
                    }
                }
                else {
                    while (count_pr1 > 0) {
                        prime_idx.push_back(fac2);
                        if (count_pr2 > 0) { 
                            prime_idx.push_back(fac1); 
                        }
                        count_pr1 --;
                        count_pr2 --;
                    }
                    if (count_pr2 > 0) {
                        prime_idx.push_back(fac1);
                    }
                }
                
                all_primes.insert(fac1);
                all_primes.insert(fac2);
                
            }
        }
        else {
            pr1 = c[0]/d;
            common = d;
            pr2 = c[1]/d;
            
            prime_idx.push_back(pr1);
            prime_idx.push_back(d);
            prime_idx.push_back(pr2);
            
            all_primes.insert(pr1);
            all_primes.insert(d);
            all_primes.insert(pr2);
            start = 2;
        }
        
        cur_value = pr2;
        for (int j = start; j < l; j ++) {
            cur_value = c[j]/cur_value;
            prime_idx.push_back(cur_value);
            all_primes.insert(cur_value);
        }
        
        int idx = 0;
        for (auto prime: all_primes) {
            sorted[idx] = prime;
            idx ++;
        }

        for (int j = 0; j < l + 1; j ++) {
            // cerr << prime_idx[j] << " ";
            for (int k = 0; k < 26; k ++) {
                if (prime_idx[j] == sorted[k]) {
                    ch = 65 + k;
                    string temp(1, ch);
                    res += temp;
                    break;
                }
            }
        }

        cout << "Case #" << i + 1 << ": " << res << endl;

        c.clear();
        res.clear();
        all_primes.clear();
        prime_idx.clear();
    }

    return 0;
}