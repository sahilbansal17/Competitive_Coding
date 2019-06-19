class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        vector <bool> done(n + 1, 0);
        map <char, char> replaced;
        for (int i = 0; i < n; i ++) {
            // already replaced the current character
            if (done[i]) {
                if (s[i] != t[i]) {
                    return 0;
                }
                continue;
            }
            // characters mismatch
            if (s[i] != t[i]) {
                // replace all further occurrences, if possible
                if (replaced.find(t[i]) == replaced.end()) {
                    char to_replace = s[i];
                    for (int j = i; j < n; j ++) {
                        if (s[j] == to_replace && !done[j]) {
                            // cout << j << endl;
                            done[j] = 1;
                            s[j] = t[i];
                        }
                    }
                    replaced[t[i]] = s[i];
                }
                else {
                    return 0;
                }
            }
            else { // characters do not mismatch
                // mark all the same characters as done 
                // so that they cannot be replaced
                if (replaced.find(t[i]) == replaced.end()) {
                    for (int j = i; j < n; j ++) {
                        if (s[j] == s[i]) {
                           done[j] = 1;
                        }
                    }
                    replaced[t[i]] = s[i];
                }
                else {
                    return 0;
                }
            }
        }
        // compare the two strings
        for (int i = 0; i < n; i ++) {
            if (s[i] != t[i]) {
                return 0;
            }
        }
        return 1;
    }
};