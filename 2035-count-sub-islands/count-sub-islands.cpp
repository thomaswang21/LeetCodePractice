class Solution {
private:
    int M, N;

    void dfs(vector<vector<int>> &B, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || B[x][y] == 0)
            return; // 边界或水/访问过就返回
        B[x][y] = 0; // 标记访问过或沉没

        // 四个方向直接写递归
        dfs(B, x + 1, y);
        dfs(B, x - 1, y);
        dfs(B, x, y + 1);
        dfs(B, x, y - 1);
    }

public:
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
        M = A.size();
        N = A[0].size();
        int cnt = 0;

        // 先把 B 中那些在 A 里是水的部分沉掉
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0 && B[i][j] == 1) {
                    dfs(B, i, j);
                }
            }
        }

        // 剩下的 B 中的岛屿就是子岛屿
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[i][j] == 1) {
                    dfs(B, i, j);
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};