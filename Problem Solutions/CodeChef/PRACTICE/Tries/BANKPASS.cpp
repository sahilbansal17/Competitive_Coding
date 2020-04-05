#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

class Trie {
private:
    Trie* children[26];
    bool end;
public:
    /** Initialize your data structure here. */
    Trie() {
        end = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            int idx = word[i] - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new Trie;
            }
            cur = cur->children[idx];
        }
        cur->end = true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        int n = prefix.length();
        for (int i = 0; i < n; ++i) {
            int idx = prefix[i] - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        if (cur == NULL) {
            return false;
        }
        // should have one child
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (!cur->children[i]) {
                ++cnt;
            }
        }
        if (cnt == 26) {
            // no child
            return false;
        }
        return true;
    }
};

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "non vulnerable";
        return;
    }
    string pass;
    Trie* passwords = new Trie;
    vector<string> passes;
    for (int i = 0; i < n; ++i) {
        cin >> pass;
        passwords->insert(pass);
        passes.push_back(pass);
    }

    for (auto pass: passes) {
        if (passwords->startsWith(pass)) {
            cout << "vulnerable";
            return ;
        }
    }
    cout << "non vulnerable";
}

int main () {
    FAST_IO;

    solve();
    return 0;
}