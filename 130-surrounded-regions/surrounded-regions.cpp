

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 如果为空直接返回
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();

        // 定义四个方向向量（二维）
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // 定义DFS函数
        function<void(int,int)> dfs = [&](int x, int y) {
            // 越界或非 'O' 直接返回
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') return;
            // 标记为安全区域
            board[x][y] = '#';
            // 向四个方向扩展
            for (auto& d : directions) {
                dfs(x + d.first, y + d.second);
            }
        };

        // 从边界的 'O' 开始DFS
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][n-1] == 'O') dfs(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j);
            if (board[m-1][j] == 'O') dfs(m-1, j);
        }

        // 遍历整个矩阵，修改字符
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // 被包围的区域
                else if (board[i][j] == '#') board[i][j] = 'O'; // 安全区域恢复
            }
        }
    }
};

