#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MAX = 100010LL;
const ll MOD = 1e9 + 7;

class Trie {
public:
    Trie* children[26];
    int cnt;
    int len;
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        cnt = 0;
        len = 0;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            int idx = word[i] - 'A';
            if (!cur->children[idx]) {
                cur->children[idx] = new Trie;
            }
            cur = cur->children[idx];
            cur->len = (i + 1);
        }
        ++cur->cnt ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            int idx = word[i] - 'A';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        return (cur != NULL && cur->cnt > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        int n = prefix.length();
        for (int i = 0; i < n; ++i) {
            int idx = prefix[i] - 'A';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        return true;
    }
};

int rec_solve(Trie* words, Trie* par, int k) {
    int res = 0;
    if (!words) {
        return 0;
    }
    //*/
    bool nochild = true;
    for (int i = 0; i < 26; ++i) {
        if (words->children[i]) {
            nochild = false;
        }
    }
    if (nochild) {
        res = (words->cnt)/k;
        res *= words->len;
        if (par) {
            par->cnt += (words->cnt) % k;
        }
        return res;
    }
    //*/

    for (int i = 0; i < 26; ++i) {
        if (words->children[i]) {
            res += rec_solve(words->children[i], words, k);
        }
    }
    res += ((words->cnt)/k) * (words->len);
    if (par) {
        par->cnt += (words->cnt) % k;
    }
    // cout << cur << ": " << res << endl;
    return res;
}

void solve(int case_count) {

    int n, k;
    cin >> n >> k;

    vector<string> vs;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end());

    Trie* words = new Trie();
    for (int i = 0; i < n; ++i) {
        words->insert(vs[i]);
    }

    int res = rec_solve(words, NULL, k);

    cout << "Case #" << case_count << ": " << res << endl ;
    return ;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}