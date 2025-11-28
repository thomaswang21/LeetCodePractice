
// 思路：使用回溯法（Backtracking）解决N皇后问题
// 每一行放置一个皇后，确保列、主对角线、副对角线都不冲突
// 用三个数组分别标记列、主对角线、副对角线是否被占用
// 当所有行都放置完毕时，将当前棋盘加入结果集

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res; // 存储所有解
    vector<string> board; // 当前棋盘状态
    vector<int> colUsed; // 列是否被占用
    vector<int> diag1Used; // 主对角线是否被占用
    vector<int> diag2Used; // 副对角线是否被占用
    int N; // 棋盘大小

    void backtrack(int row) {
        // 如果所有行都放置完毕，加入结果
        if (row == N) {
            res.push_back(board);
            return;
        }
        // 遍历每一列尝试放置皇后
        for (int col = 0; col < N; col++) {
            // 检查列、主对角线、副对角线是否冲突
            if (colUsed[col] || diag1Used[row - col + N - 1] || diag2Used[row + col])
                continue;
            // 放置皇后
            board[row][col] = 'Q';
            colUsed[col] = 1;
            diag1Used[row - col + N - 1] = 1;
            diag2Used[row + col] = 1;
            // 递归下一行
            backtrack(row + 1);
            // 回溯，移除皇后
            board[row][col] = '.';
            colUsed[col] = 0;
            diag1Used[row - col + N - 1] = 0;
            diag2Used[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        res.clear();
        board = vector<string>(n, string(n, '.'));
        colUsed = vector<int>(n, 0);
        diag1Used = vector<int>(2 * n - 1, 0);
        diag2Used = vector<int>(2 * n - 1, 0);
        backtrack(0);
        return res;
    }
};
