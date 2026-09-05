class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // prefix[i][j] 用于存储从 (0,0) 到 (i-1, j-1) 的子矩阵元素之和
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        // 1. 预计算 2D 前缀和矩阵
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        vector<vector<int>> answer(m, vector<int>(n, 0));
        
        // 2. 在 O(1) 时间内计算每个中心点的区块和
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 确定区块的有效边界
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);
                
                // 容斥原理：利用前缀和数组快速求出局部子矩阵的面积（和）
                answer[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            }
        }
        
        return answer;
    }
};