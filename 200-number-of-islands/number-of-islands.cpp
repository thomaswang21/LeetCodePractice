class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // 访问标记数组

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        // 边界条件 + 已访问或水
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == '0') 
            return;

        visited[i][j] = true; // 标记为已访问

        // 上下左右递归
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }
};
