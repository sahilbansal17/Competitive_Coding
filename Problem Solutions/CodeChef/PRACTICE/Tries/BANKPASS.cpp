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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            int idx = word[i] - 'a';
            if (!cur->children[idx]) {
                return false;
            }
            cur = cur->children[idx];
        }
        return (cur != NULL && cur->end);
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
        return true;
    }
};

void solve() {
    int n;
    cin >> n;

    string pass;
    Trie* passwords = new Trie;
    for (int i = 0; i < n; ++i) {
        cin >> pass;
        if (passwords->startsWith(pass)) {
            cout << "vulnerable";
            return ;
        }
        passwords->insert(pass);
    }
    cout << "non vulnerable";
}

int main () {
    FAST_IO;

    solve();
    return 0;
}