
// 思路：使用动态规划。dp[i] 表示前 i 个房子能偷到的最大金额。
// 状态转移方程：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
// 因为不能偷相邻的房子，所以每次选择偷或不偷当前房子。
// 最后返回 dp[n-1]。

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // 没有房子
        if (n == 1) return nums[0]; // 只有一个房子

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            // 选择偷当前房子或不偷
            if (dp[i - 1] > dp[i - 2] + nums[i]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 2] + nums[i];
            }
        }

        return dp[n - 1];
    }
};
