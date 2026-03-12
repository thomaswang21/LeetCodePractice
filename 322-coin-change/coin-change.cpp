
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 创建 dp 数组，大小为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // 凑成 0 元需要 0 个硬币

        // 遍历所有金额
        for (int i = 1; i <= amount; i++) {
            // 遍历每个硬币
            for (int coin : coins) {
                if (i - coin >= 0) {
                    // 状态转移：选择当前硬币 coin
                    if (dp[i - coin] + 1 < dp[i]) {
                        dp[i] = dp[i - coin] + 1;
                    }
                }
            }
        }

        // 如果无法凑出目标金额，返回 -1
        if (dp[amount] > amount) {
            return -1;
        }
        return dp[amount];
    }
};



