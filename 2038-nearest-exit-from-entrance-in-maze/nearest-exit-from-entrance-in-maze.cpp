#include <vector>
#include <queue>

class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        std::vector<std::vector<int>> dirs = {{1,0}, {0, -1}, {0, 1}, {-1, 0}};

        // BFS 算法的队列和 visited 数组
        std::queue<std::vector<int>> queue;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        queue.push(entrance);
        visited[entrance[0]][entrance[1]] = true;
        
        // 启动 BFS 算法从 entrance 开始像四周扩散
        int step = 0;
        while (!queue.empty()) {
            int sz = queue.size();
            step++;
            // 扩散当前队列中的所有节点
            for (int i = 0; i < sz; i++) {
                std::vector<int> cur = queue.front();
                queue.pop();
                // 每个节点都会尝试向上下左右四个方向扩展一步
                for (const auto& dir : dirs) {
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || maze[x][y] == '+') {
                        continue;
                    }
                    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                        // 走到边界（出口）
                        return step;
                    }
                    visited[x][y] = true;
                    queue.push({x, y});
                }
            }
        }
        return -1;
    }
};