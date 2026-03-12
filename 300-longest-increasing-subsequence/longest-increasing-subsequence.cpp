

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // 每个元素至少能构成长度为1的递增子序列
        int ans = 1;

        // 双层循环计算每个位置的最长递增子序列长度
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // 如果前面的数比当前数小
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1; // 更新dp[i]
                    }
                }
            }
            if (ans < dp[i]) {
                ans = dp[i]; // 更新全局最大值
            }
        }

        return ans;
    }
};

