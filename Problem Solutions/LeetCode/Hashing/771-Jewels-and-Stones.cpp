class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (auto jewel: J) {
            jewels.insert(jewel);
        }
        int res = 0;
        for (auto stone: S) {
            if (jewels.find(stone) != jewels.end()) {
                ++res;
            }
        }
        return res;
    }
};