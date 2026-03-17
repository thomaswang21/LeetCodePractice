class Solution {
public:
    // 函数 minFallingPathSum
    // 时间复杂度：O(n^2)    空间复杂度：O(1) 原地覆盖
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // n为正方形矩阵的边长
        int n = (int)matrix.size();                  // 取矩阵边长
        // 二维方向数组 表示从上一行的三个可能来源
        vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1}}; // 三种方向

        // 从第1行开始逐行更新
        for (int i = 1; i < n; i++) {                // 遍历行 从1到n-1
            for (int j = 0; j < n; j++) {            // 遍历列 从0到n-1
                int best = INT_MAX;                  // 记录三个来源的最小值
                for (int k = 0; k < 3; k++) {        // 遍历三个方向
                    int pi = i + dirs[k][0];         // 上一行的行坐标 i-1
                    int pj = j + dirs[k][1];         // 上一行的列坐标 j-1, j, j+1
                    // 判界 只有合法来源才参与最小值计算
                    if (pi >= 0) {                   // 行必然>=0 因为i>=1 但保持形式统一
                        if (pj >= 0) {               // 左边界检查
                            if (pj < n) {            // 右边界检查
                                if (matrix[pi][pj] < best) { // 更新最小来源
                                    best = matrix[pi][pj];   // 记录更小的来源值
                                }
                            }
                        }
                    }
                }
                // 将当前格更新为 原值 + 最小来源
                matrix[i][j] = matrix[i][j] + best;  // 原地覆盖 保持只读上一行
            }
        }

        // 扫描最后一行 取最小值作为答案
        int ans = INT_MAX;                           // 初始化答案为无穷大
        for (int j = 0; j < n; j++) {                // 遍历最后一行所有列
            if (matrix[n-1][j] < ans) {              // 找更小的
                ans = matrix[n-1][j];                // 更新答案
            }
        }
        return ans;                                   // 返回最终结果
    }
};