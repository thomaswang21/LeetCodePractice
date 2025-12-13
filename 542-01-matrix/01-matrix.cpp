#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // 记录答案的结果数组
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // 初始化全部填充特殊值 -1，代表未计算，
        // 待会可以用来判断坐标是否已经计算过，避免重复遍历
        
        // 初始化队列，把那些值为 0 的坐标放到队列里
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        // 执行 BFS 算法框架，从值为 0 的坐标开始向四周扩散
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            // 向四周扩散
            for (auto& dir : dirs) {
                int nextX = x + dir.first;
                int nextY = y + dir.second;
                // 确保相邻的这个坐标没有越界且之前未被计算过
                if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && res[nextX][nextY] == -1) {
                    q.push({nextX, nextY});
                    // 从 mat[x][y] 走到 mat[nextX][nextY] 需要一步
                    res[nextX][nextY] = res[x][y] + 1;
                }
            }
        }

        return res;
    }
};