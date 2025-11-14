class Solution {
public:
    int ans = 0;

    void dfs(int i, int curXor, vector<int>& nums) {
        if (i == nums.size()) {
            ans += curXor;
            return;
        }

        // 1. 不选 nums[i]
       

        // 2. 选 nums[i]
        dfs(i + 1, curXor ^ nums[i], nums);
         dfs(i + 1, curXor, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        dfs(0, 0, nums);
        return ans;
    }
};
