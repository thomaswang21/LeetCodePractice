

class Solution {
public:
    // 主函数时间复杂度 O(m*n)，空间复杂度 O(m*n)
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 初始化边界条件
        for (int i = 0; i <= m; i++) dp[i][0] = i; // 删除操作
        for (int j = 0; j <= n; j++) dp[0][j] = j; // 插入操作

        // 填表
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 字符相同，无需操作
                } else {
                    int insertOp = dp[i][j - 1] + 1;   // 插入
                    int deleteOp = dp[i - 1][j] + 1;   // 删除
                    int replaceOp = dp[i - 1][j - 1] + 1; // 替换
                    dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }

        return dp[m][n];
    }
};


