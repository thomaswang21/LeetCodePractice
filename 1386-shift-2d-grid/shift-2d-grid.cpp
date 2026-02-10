class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();           // 行数
        int m = grid[0].size();        // 列数
        int total = n * m;             // 总元素数

        vector<vector<int>> ans(n, vector<int>(m)); // 初始化结果网格

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // 将 (i, j) 映射为一维下标
                int index = i * m + j;

                // 向右移动 k 步后得到的新一维下标
                int newIndex = (index + k) % total;

                // 再从一维下标映射回二维坐标
                int newI = newIndex / m;
                int newJ = newIndex % m;

                // 将 grid[i][j] 移动到新位置
                ans[newI][newJ] = grid[i][j];
            }
        }

        return ans;
    }
};
