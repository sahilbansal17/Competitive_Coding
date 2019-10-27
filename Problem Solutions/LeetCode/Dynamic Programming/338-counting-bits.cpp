class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> setBits(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            setBits[i] = (i & 1) ? 1 + setBits[i/2] : setBits[i/2];
        }
        return setBits;
    }
};