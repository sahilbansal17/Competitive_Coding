class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // unordered_set<int> seen;
        unordered_map<int, int> seenIndex;
        vector<int> res;
        for (int idx = 0; idx < n; ++idx) {
            int num = nums[idx];
            int other = target - num;
            if (seenIndex.find(other) != seenIndex.end()) {
                res.push_back(idx);
                res.push_back(seenIndex[other]);
                return res;
            }
            seenIndex[num] = idx;
        }
        return res;
    }
};