class Solution 
{
public:
    int tribonacci(int n) 
    {
        //处理边界情况
        if( n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1);
        // 初始化
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        // 状态转移方程
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};
