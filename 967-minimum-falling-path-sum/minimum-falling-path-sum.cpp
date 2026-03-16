

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // 获取矩阵大小
        // 从第二行开始逐行更新
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minAbove = matrix[i - 1][j]; // 上方
                if (j > 0) { // 左上方
                    if (matrix[i - 1][j - 1] < minAbove) {
                        minAbove = matrix[i - 1][j - 1];
                    }
                }
                if (j < n - 1) { // 右上方
                    if (matrix[i - 1][j + 1] < minAbove) {
                        minAbove = matrix[i - 1][j + 1];
                    }
                }
                matrix[i][j] += minAbove; // 更新当前格子的最小路径和
            }
        }
        // 找到最后一行中的最小值
        int res = matrix[n - 1][0];
        for (int j = 1; j < n; j++) {
            if (matrix[n - 1][j] < res) {
                res = matrix[n - 1][j];
            }
        }
        return res;
    }
};
