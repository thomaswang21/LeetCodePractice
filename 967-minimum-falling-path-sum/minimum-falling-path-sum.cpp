class Solution {
public:
    // 时间复杂度 O(n^2)，空间复杂度 O(1)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // 获取矩阵大小
        for (int i = 1; i < n; i++) { // 从第二行开始
            for (int j = 0; j < n; j++) { // 遍历每一列
                int up = matrix[i-1][j]; // 上方
                int left = (j > 0) ? matrix[i-1][j-1] : INT_MAX; // 左上方
                int right = (j < n-1) ? matrix[i-1][j+1] : INT_MAX; // 右上方
                matrix[i][j] += min(up, min(left, right)); // 当前值加上最小路径
            }
        }
        int ans = INT_MAX; // 记录最小结果
        for (int j = 0; j < n; j++) { // 遍历最后一行
            ans = min(ans, matrix[n-1][j]); // 找最小值
        }
        return ans; // 返回结果
    }
};