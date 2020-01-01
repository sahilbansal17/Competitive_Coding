#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<int> solve(set<string>& sset0, set<string>& sset1, unordered_map<string, int>& idx) {
    auto it1 = sset0.begin();
    auto it2 = sset1.begin();
    vector<int> idxs;
    bool possible = true;
    
    int cnt[2][2] = {{0}}; // cnt[i][j] denotes count starting with i and ending with j
    for (auto s: sset0) {
        if (s.back() == '0') {
            ++cnt[0][0];
        } else {
            ++cnt[0][1];
        }
    }
    for (auto s: sset1) {
        if (s.back() == '0') {
            ++cnt[1][0];
        } else {
            ++cnt[1][1];
        }
    }

    if (cnt[0][0] > 0 && cnt[1][1] > 0 && cnt[0][1] == 0 && cnt[1][0] == 0) {
        possible = false;
    } else if (abs(cnt[0][1] - cnt[1][0]) > 1) {
        int diff = abs(cnt[0][1] - cnt[1][0]);
        int rev = ceil(1.0*(diff - 1)/2.0);
        if (cnt[0][1] > cnt[1][0]) {
            int done = 0;
            for (auto s: sset0) {
                if (s.back() == '1') {
                    reverse(s.begin(), s.end());
                    bool this_done = false;
                    if (sset1.find(s) == sset1.end()) {
                        ++done;
                        this_done = true;
                    }
                    reverse(s.begin(), s.end());
                    if (this_done) {
                        idxs.push_back(idx[s]);
                    }
                    if (done == rev) {
                        break;
                    }
                }
            }
        } else {
            int done = 0;
            for (auto s: sset1) {
                if (s.back() == '0') {
                    reverse(s.begin(), s.end());
                    bool this_done = false;
                    if (sset0.find(s) == sset0.end()) {
                        ++done;
                        this_done = true;
                    }
                    reverse(s.begin(), s.end());
                    if (this_done) {
                        idxs.push_back(idx[s]);
                    }
                    if (done == rev) {
                        break;
                    }
                }
            }
        }
    }
    if (!possible) {
        return {-1};
    }
    return idxs;
}

int main() {
    FAST_IO;
    int t;
    cin >> t;

    int n, l;
    string s;
    while (t--) {
        cin >> n;
        vector<string> vs;

        set<string> sset[2];
        unordered_map<string, int> idx;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (s[0] == '0') {
                sset[0].insert(s);
            } else {
                sset[1].insert(s);
            }
            idx[s] = i;
        }

        if (n == 1) { 
            cout << "0\n\n";
            continue;
        }
        
        vector<int> res = solve(sset[0], sset[1], idx);
        n = res.size();
        if (n == 0) {
            cout << "0\n\n";
            continue;
        }
        if (res[0] == -1) {
            cout << "-1\n";
            continue;
        }
        cout << n << endl;
        for (int j = 0; j < n; ++j) {
            cout << 1 + res[j] << " ";
        }
        cout << endl;
    }

    return 0;
}