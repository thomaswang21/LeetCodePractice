class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If total sum is odd, we can't divide it into two equal integer subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        
        // dp[i] will be true if a sum of i can be achieved
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible

        for (int num : nums) {
            // Iterate backwards to avoid using the same element twice
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};