#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

bool len_function (string a, string b) {
    int m = a.length();
    int n = b.length();
    return m <= n;
}
void solve(int case_no) {

    int n;
    cin >> n;

    vector<string> left, right;
    string mid = "";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        int j1 = s.find("*");
        int j2 = s.find_last_of("*");
        if (j1 != 0) {
            left.push_back(s.substr(0, j1));
        }
        if (j2 != s.length() - 1) {
            right.push_back(s.substr(j2 + 1));
        }
        string temp = "";
        for (int j = j1 + 1; j < j2; ++j) {
            if (s[j] != '*') {
                temp += s[j];
            }
        }
        mid += temp;
    }

    int ls = left.size();
    int rs = right.size();
    if (ls >= 1) {
        sort(left.begin(), left.end(), len_function);
    }
    if (rs >= 1) {
        sort(right.begin(), right.end(), len_function);
    }
    
    string ansleft = "";
    for (int i = 0; i < ls; ++i) {
        if (left[i].length() >= ansleft.length()) {
            ansleft = left[i];
        }
    }
    string ansright = "";
    for (int i = 0; i < rs; ++i) {
        if (right[i].length() >= ansright.length()) {
            ansright = right[i];
        }
    }

    int p1 = ansleft.length();
    int p2 = ansright.length();
    
    bool poss = true;
    if (ls >= 2) {
        for (int i = 0; i <= ls - 1; ++i) {
            string s = left[i];
            int m = s.length();
            if (m == 0) {
                continue;
            }
            for (int j = 0; j < min(m, p1); ++j) {
                if (s[j] != ansleft[j]) {
                    poss = false;
                    break;
                }
            }
            if (poss == false) {
                break;
            }
        }
    }
    if (rs >= 2) {
        for (int i = 0; i <= rs - 1; ++i) {
            string s = right[i];
            int m = s.length();
            if (m == 0) {
                continue;
            }
            for (int j = 0; j < min(m, p2); ++j) {
                if (s[m - j - 1] != ansright[p2 - j - 1]) {
                    poss = false;
                    break;
                }
            }
            if (poss == false) {
                break;
            }
        }
    }
    string res;
    if (!poss) {
        res = "*";
    } else {
        res = ansleft;
        res += mid;
        res += ansright;
    }
    cout << "Case #" << case_no << ": " << res << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int id = 1; id <= t; ++id) {
        solve(id);
    }
    
    return 0;
}