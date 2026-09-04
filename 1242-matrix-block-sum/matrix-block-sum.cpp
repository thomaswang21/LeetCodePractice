class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // 1. 构建前缀和数组（大一圈，防止越界）
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 完全使用你刚才推导理解的公式
                prefix[i+1][j+1] = mat[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        // 2. 遍历每个格子，计算它周围一圈的和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 确定目标区域的上下左右边界，并防止越界
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);
                
                // 套用 sumRegion 公式求这个矩形区域的总和
                // 注意代入 prefix 数组时，右下角坐标需要 +1
                ans[i][j] = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
            }
        }
        
        return ans;
    }
};