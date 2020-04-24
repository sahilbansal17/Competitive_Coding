#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

vector<string> dig = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int calc(string& s1, string& s2) {
    int res = 0;
    for (int i = 0; i < 7; ++i) {
        if (s1[i] == '0' && s2[i] == '1') {
            ++res;
        } else if (s1[i] == '1' && s2[i] == '0') {
            res = -1;
            break;
        }
    }
    return res;
}

int solved[2010][2010];
int solve(int cur, int k, vector<string>& vs) {
    if (k < 0) {
        return 0;
    }
    if (cur == vs.size()) {
        if (k != 0) {
            return solved[cur][k] = 0;
        }
        return solved[cur][k] = 1;
    }
    if (solved[cur][k] != -1) {
        return solved[cur][k];
    }
    int nextpossible;
    for (int i = 9; i >= 0; --i) {
        int c = calc(vs[cur], dig[i]);
        if (c == -1) {
            continue;
        }
        nextpossible = solve(cur + 1, k - c, vs);
        if (!nextpossible) {
            continue;
        }
        break;
    }
    return solved[cur][k] = nextpossible;
}
int main() {
    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<string> vs;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vs.push_back(s);
    }
    
    memset(solved, -1, sizeof(solved));

    bool possible = solve(0, k, vs);
    if (!possible) {
        cout << "-1" << endl;
    } else {
        int cur = 0;
        vector<char> res;
        while (cur < n) {
            for (int c = 9; c >= 0; --c) {
                int dist = calc(vs[cur], dig[c]);
                if (k - dist < 0) {
                    continue;
                }
                if (solved[cur + 1][k - dist] == 1) {
                    res.push_back(char(48 + c));
                    k -= dist;
                    break;
                }
            }
            ++cur;
        }
        string ans(res.begin(), res.end());
        cout << ans << endl;
    }
    return 0;
}
