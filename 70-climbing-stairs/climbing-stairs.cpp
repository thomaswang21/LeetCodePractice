#include <vector>

class Solution {
public:
    // 备忘录
    std::vector<int> memo;

    int climbStairs(int n) {
        memo.resize(n + 1, 0);
        return dp(n);
    }

    // 定义：爬到第 n 级台阶的方法个数为 dp(n)
    int dp(int n) {
        // base case
        if (n <= 2) {
            return n;
        }
        if (memo[n] > 0) {
            return memo[n];
        }
        // 状态转移方程：
        // 爬到第 n 级台阶的方法个数等于爬到 n - 1 的方法个数和爬到 n - 2 的方法个数之和。
        memo[n] = dp(n - 1) + dp(n - 2);
        return memo[n];
    }
};


// 该算法时间复杂度为 O(n)，空间复杂度为 O(1)，是最优解法。