

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 主函数时间复杂度 O(m*n)，空间复杂度 O(m*n)
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // dp[i][j] 表示 word1前i个字符与word2前j个字符的最长公共子序列长度
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字符相同，LCS长度+1
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 否则取较大值
                }
            }
        }

        int lcs = dp[m][n];
        return (m - lcs) + (n - lcs); // 删除非LCS部分
    }
};

