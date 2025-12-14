
// 思路说明：
// 题目要求找到从矩阵第一行到最后一行的“下降路径”的最小和。
// 每次可以从 (i, j) 走到下一行的 (i+1, j-1)、(i+1, j)、(i+1, j+1)。
// 使用动态规划（DP）解决。
// dp[i][j] 表示到达 (i, j) 的最小路径和。
// 状态转移：dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1])
// 注意边界：当 j=0 或 j=n-1 时要避免越界。
// 最终答案是 dp[n-1][j] 的最小值。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // DP 数组初始化

        // 第一行直接等于原矩阵的值
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // 从第二行开始计算
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minPrev = dp[i - 1][j];
                if (j > 0 && dp[i - 1][j - 1] < minPrev) {
                    minPrev = dp[i - 1][j - 1];
                }
                if (j < n - 1 && dp[i - 1][j + 1] < minPrev) {
                    minPrev = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + minPrev;
            }
        }

        // 找出最后一行的最小值
        int ans = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            if (dp[n - 1][j] < ans) {
                ans = dp[n - 1][j];
            }
        }
        return ans;
    }
};


