class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % k != 0) return false;
        int target = sum / k;
        vector<int> subsets(k, 0);

        sort(nums.rbegin(), nums.rend());

        return backtrack(nums, subsets, 0, target);
    }

    bool backtrack(vector<int>& nums, vector<int>& subsets, int index, int target) {
        if (index == nums.size()) {
            for (int sum : subsets) if (sum != target) return false;
            return true;
        }

        for (int i = 0; i < subsets.size(); i++) {
            if (subsets[i] + nums[index] > target) continue;
            subsets[i] += nums[index];
            if (backtrack(nums, subsets, index + 1, target)) return true;
            subsets[i] -= nums[index];

            // 关键剪枝：空子集尝试失败 → 其他空子集不必再尝试
            if (subsets[i] == 0) break;
        }

        return false;
    }
};
