class Solution {
private:
    int cnt[26];
public:
    bool allDistinct() {
        bool res = true;
        for (int i = 0; i < 26; i ++) {
            if (cnt[i] > 1) {
                res = false;
            }
        }
        return res;
    }
    int numKLenSubstrNoRepeats(string S, int K) {
        memset(cnt, sizeof(cnt), 0);
        int len = S.length();
        for (int i = 0; i < min(K, len); i ++) {
            cnt[S[i] - 'a'] ++;
        }
        int result = 0;
        if (K <= len && allDistinct()) {
            result ++;
        }
        for (int i = K; i < len; i ++) {
            cnt[S[i] - 'a'] ++;
            cnt[S[i-K] - 'a'] --;
            if (allDistinct()) {
                result ++;
            }
        }
        return result;
    }
};