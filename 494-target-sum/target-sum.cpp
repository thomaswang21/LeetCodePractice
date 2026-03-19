// 时间复杂度: O(n * sum)
// 空间复杂度: O(sum)

#include <bits/stdc++.h>
using namespace std;

// 主函数：计算目标和的方案数
// 时间复杂度: O(n * sum)
// 空间复杂度: O(sum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        // 如果 (sum + target) 不是偶数 或 target 超出范围，直接返回 0
        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;

        int P = (sum + target) / 2;

        // dp[i] 表示和为 i 的方案数
        vector<int> dp(P + 1, 0);
        dp[0] = 1; // 和为 0 的方案只有一种：不选任何数

        // 遍历每个数字
        for (int num : nums) {
            // 从后往前遍历，避免重复使用同一个数
            for (int j = P; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[P];
    }
};

