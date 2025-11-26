class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // 必须排序才能去重
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 已经使用过，跳过
            if (used[i]) continue;

            // 去重逻辑（最关键）
            // 如果 nums[i] == nums[i-1] 且前一个相同数字没使用过，则跳过
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            // 做选择
            track.push_back(nums[i]);
            used[i] = true;

            backtrack(nums);

            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};
