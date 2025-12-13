class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        // 需要记录走过的路径，避免死循环
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // 初始化队列，从 (0, 0) 出发
        q.push({0, 0});
        visited[0][0] = true;
        int pathLen = 1;

        // 执行 BFS 算法框架，从值为 0 的坐标开始向八个方向扩散
        vector<vector<int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        while (!q.empty()) {
            int sz = q.size();
            for (int __ = 0; __ < sz; __++) {
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second;
                if (x == m - 1 && y == n - 1) {
                    return pathLen;
                }
                // 向八个方向扩散
                for (int i = 0; i < 8; i++) {
                    int nextX = x + dirs[i][0];
                    int nextY = y + dirs[i][1];
                    // 确保相邻的这个坐标没有越界且值为 0 且之前没有走过
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n
                        && grid[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                        q.push({nextX, nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
            pathLen++;
        }
        return -1;
    }
};

