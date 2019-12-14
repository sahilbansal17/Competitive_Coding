/*
 * Gives wrong answer
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<int> solve(bool status, set<string>& sset0, set<string>& sset1, unordered_map<string, int>& idx) {
    int res = 0;
    auto it1 = sset0.begin();
    auto it2 = sset1.begin();
    bool zero = status;
    string cur, next;
    vector<int> idxs;
    int l;
    while (it1 != sset0.end() && it2 != sset1.end()) {
        if (zero) {
            cur = *it1;
            l = cur.length();
            if (cur[l - 1] == '0') {
                ++it1;
            } else {
                ++it1;
                zero = false;
            }
        } else {
            cur = *it2;
            l = cur.length();
            if (cur[l - 1] == '1') {
                ++it2;
            } else {
                ++it2;
                zero = true;
            }
        }
    }
    bool possible = true;
    while (it1 != sset0.end()) {
        cur = *it1;
        // cout << "c: " << cur << endl;
        l = cur.length();
        if (zero) {
            if (cur[l - 1] == '0') {
                ++it1;
            } else {
                ++it1;
                zero = false;
            }
        } else {
            if (cur[l - 1] == '0') {
                possible = false;
                break;
            }
            reverse(cur.begin(), cur.end());
            if (sset1.find(cur) == sset1.end()) {
                ++res;
                reverse(cur.begin(), cur.end());
                // cout << "i: " << cur << endl;
                idxs.push_back(idx[cur]);
                ++it1;
                zero = true;
            } else {
                possible = false;
                break;
            }
        }
    }
    if (!possible) {
        // cout << "-1" << endl;
        return {-1};
    }
    while (it2 != sset1.end()) {
        cur = *it2;
        l = cur.length();
        if (!zero) {
            if (cur[l - 1] == '1') {
                ++it2;
            } else {
                ++it2;
                zero = true;
            }
        } else {
            if (cur[l - 1] == '1') {
                possible = false;
                break;
            }
            reverse(cur.begin(), cur.end());
            if (sset0.find(cur) == sset0.end()) {
                ++res;
                reverse(cur.begin(), cur.end());
                // cout << "i: " << cur << endl;
                idxs.push_back(idx[cur]);
                ++it2;
                zero = false;
            } else {
                possible = false;
                break;
            }
        }
    }
    if (!possible) {
        // cout << "-1" << endl;
        return {-1};
    } 
    /*
    cout << res << endl;
    if (res == 0) {
        cout << endl;
    } else {
        for (int j = 0; j < res; ++j) {
            cout << 1 + idxs[j] << " ";
        }
        cout << endl;
    }
    */
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
        
        vector<int> res1 = solve(true, sset[0], sset[1], idx);
        vector<int> res2 = solve(false, sset[0], sset[1], idx);

        int n1 = res1.size();
        int n2 = res2.size();
        if (n1 == 0 || n2 == 0) {
            cout << "0\n\n";
            continue;
        }
        if (res1[0] == -1 && res2[0] == -1) {
            cout << "-1\n";
            continue;
        }
        if (res1[0] != -1 && n1 <= n2) {
            // cout << "n1: ";
            cout << n1 << endl;
            for (int j = 0; j < n1; ++j) {
                cout << 1 + res1[j] << " ";
            }
            cout << endl;
        } else if (res2[0] != -1 && n2 <= n1) {
            // cout << "n2: ";
            cout << n2 << endl;
            for (int j = 0; j < n2; ++j) {
                cout << 1 + res2[j] << " ";
            }
            cout << endl;
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}