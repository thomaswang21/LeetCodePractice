class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dfs(int x, int y) {
        int res = 1;
        g[x][y] = 1;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) {
                res = 0;
                continue;
            }
            if (!g[a][b] && !dfs(a, b))
                res = 0;
        }
        return res;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        g = grid;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!g[i][j])
                    res += dfs(i, j);
        return res;
    }
};

