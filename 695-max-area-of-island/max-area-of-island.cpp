class Solution {
public:
    int rows;
    int cols;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();
        int area = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // 访问标记数组

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    area = max(area, dfs(grid, i, j, visited));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        rows = grid.size();
        cols = grid[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true; // 标记为已访问
        int res = 1;

        res += dfs(grid, i + 1, j, visited);
        res += dfs(grid, i - 1, j, visited);
        res += dfs(grid, i, j + 1, visited);
        res += dfs(grid, i, j - 1, visited);

        return res;
    }
};
