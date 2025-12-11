class Solution {
public:
    int n, m;
    vector<vector<bool>> st;

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m, false));

        // 从四条边的 'O' 开始 DFS
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        // 把不安全的 O 变成 X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!st[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        st[x][y] = true;

        static int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

        for (auto& d : dirs) {
            int a = x + d[0];
            int b = y + d[1];
            if (a >= 0 && a < n && b >= 0 && b < m 
                && !st[a][b] && board[a][b] == 'O') {
                dfs(a, b, board);
            }
        }
    }
};
