
// 思路：
// 这是打家劫舍 II 问题，房屋是环形排列的，首尾相连。
// 环形意味着不能同时抢第一个和最后一个房子。
// 因此可以拆分为两个线性问题：
// 1. 抢第 0 到 n-2 个房子
// 2. 抢第 1 到 n-1 个房子
// 分别计算两种情况下的最大值，然后取较大者。
// 每个线性问题使用动态规划解决：dp[i] 表示前 i 个房子的最大收益。

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 特殊情况处理
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // 计算两种情况
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    // 计算线性区间 [start, end] 的最大收益
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]
        int curr = 0;   // 当前 dp[i]

        for (int i = start; i <= end; i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
