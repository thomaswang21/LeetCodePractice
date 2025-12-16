class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        // 1. 将初始网格转换为字符串状态 "110211..."
        string start = "";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                start += to_string(grid[i][j]);

        string target = "111111111";
        if (start == target) return 0;

        // BFS 标准套路：队列 + 哈希表(visited)
        queue<pair<string, int>> q; // {当前状态, 当前步数}
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右

        while (!q.empty()) {
            auto [curState, steps] = q.front();
            q.pop();

            // 遍历当前状态的 9 个位置
            for (int i = 0; i < 9; ++i) {
                // 只有当前位置有多余石头(>1)才能移动
                if (curState[i] > '1') {
                    int r = i / 3;
                    int c = i % 3;

                    // 尝试往 4 个方向移动一步
                    for (auto& d : dirs) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        // 检查边界
                        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
                            int nextPos = nr * 3 + nc;
                            
                            // 生成新状态：原位置-1，新位置+1
                            string nextState = curState;
                            nextState[i]--; 
                            nextState[nextPos]++;

                            // 如果到达目标，直接返回步数+1
                            if (nextState == target) return steps + 1;

                            // 如果没见过这个状态，入队
                            if (!visited.count(nextState)) {
                                visited.insert(nextState);
                                q.push({nextState, steps + 1});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};