class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> f(target + 1); // unsigned 是 2^32 - 1, 题目中保证答案32位 而int是 2^31 - 1
        f[0] = 1;

        for (int j = 1; j <= target; j ++ ) // 外层 是 背包，注意 j 不是从 0 开始
            for (auto& x : nums)            // 内层 是 物品
                if (j >= x) f[j] += f[j - x];

        return f[target];
    }
};





