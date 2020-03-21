class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_with_idx;
        for (int i = 0; i < nums.size(); ++i) {
            nums_with_idx.push_back({nums[i], i});
        }
        
        sort(nums_with_idx.begin(), nums_with_idx.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int cur_sum = nums_with_idx[l].first + nums_with_idx[r].first;
            if (cur_sum == target) {
                return {nums_with_idx[l].second, nums_with_idx[r].second};
            } else if (cur_sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {};
    }
};