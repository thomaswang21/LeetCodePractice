class Solution {
public:
    // Dijkstra 算法，计算 (0, 0) 到 (m - 1, n - 1) 的最小体力消耗
    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights);
    }

    // 记录当前位置和从起点到当前位置的最小体力消耗
    struct State {
        int row;
        int col;
        int effortFromStart;
        State(int row, int col, int effortFromStart)
            : row(row), col(col), effortFromStart(effortFromStart) {}
        // For priority_queue (min-heap)
        bool operator>(const State& other) const {
            return effortFromStart > other.effortFromStart;
        }
    };

    // Dijkstra 算法模板 https://labuladong.online/algo/data-structure/dijkstra/
    int dijkstra(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 记录从起点 (0, 0) 到每个节点的最小体力消耗
        vector<vector<int>> distTo(m, vector<int>(n, -1));

        priority_queue<State, vector<State>, greater<State>> pq;

        // 从起点 (0, 0) 开始进行 dijkstra 算法
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            State state = pq.top();
            pq.pop();
            int curRow = state.row;
            int curCol = state.col;
            int curEffortFromStart = state.effortFromStart;

            if (distTo[curRow][curCol] != -1) {
                continue;
            }

            distTo[curRow][curCol] = curEffortFromStart;

            // 如果 curNode 是终点 dst，直接返回最小路径权重和
            if (curRow == m - 1 && curCol == n - 1) {
                return curEffortFromStart;
            }

            for (const auto& neighbor : adj(matrix, curRow, curCol)) {
                int nextRow = neighbor[0];
                int nextCol = neighbor[1];
                int nextEffortFromStart = max(curEffortFromStart, abs(matrix[nextRow][nextCol] - matrix[curRow][curCol]));

                if (distTo[nextRow][nextCol] != -1) {
                    continue;
                }
                pq.emplace(nextRow, nextCol, nextEffortFromStart);
            }
        }

        return -1;
    }

    // 返回坐标 (x, y) 的上下左右相邻坐标
    vector<vector<int>> adj(const vector<vector<int>>& matrix, int x, int y) {
        // 方向数组，上下左右的坐标偏移量
        static const vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int m = matrix.size(), n = matrix[0].size();
        // 存储相邻节点
        vector<vector<int>> neighbors;
        for (const auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= m || nx < 0 || ny >= n || ny < 0) {
                // 索引越界
                continue;
            }
            neighbors.push_back({ nx, ny });
        }
        return neighbors;
    }
};