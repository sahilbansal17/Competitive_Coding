#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define MULTIPLE_TESTS 1

typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    set<char> distinct(s.begin(), s.end());
    int required = distinct.size();
    
    vector<int> freq(128, 0);
    vector<bool> is_distinct(128, false);
    for (char c : distinct) {
        is_distinct[c] = true;
    }
    
    int left = 0, formed = 0, min_len = INT_MAX;
    
    for (int right = 0; right < n; right++) {
        char c = s[right];
        freq[c]++;
        
        if (is_distinct[c] && freq[c] == 1) {
            formed++;
        }
        
        while (formed == required && left <= right) {
            min_len = min(min_len, right - left + 1);
            
            char d = s[left];
            freq[d]--;

            if (is_distinct[d] && freq[d] == 0) {
                formed--;
            }
            left++;
        }
    }
    
    cout << min_len << endl;
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