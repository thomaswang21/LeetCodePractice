
// 思路：使用动态规划，dp[i][j] 表示 text1 前 i 个字符与 text2 前 j 个字符的最长公共子序列长度
// 若 text1[i-1] == text2[j-1]，则 dp[i][j] = dp[i-1][j-1] + 1
// 否则 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// 最终答案为 dp[m][n]

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 创建二维 DP 数组

        // 填充 DP 表
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字符相等，取左上角加一
                } else {
                    if (dp[i - 1][j] > dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j]; // 取上方较大值
                    } else {
                        dp[i][j] = dp[i][j - 1]; // 取左方较大值
                    }
                }
            }
        }

        return dp[m][n]; // 返回最终结果
    }
};
