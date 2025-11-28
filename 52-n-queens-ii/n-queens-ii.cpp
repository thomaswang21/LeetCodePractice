#include <vector>
using namespace std;

class Solution {
public:
    int count;                  // 存储解的数量
    vector<int> colUsed;        // 列是否被占用
    vector<int> diag1Used;      // 主对角线是否被占用
    vector<int> diag2Used;      // 副对角线是否被占用
    int N;                      // 棋盘大小

    void backtrack(int row) {
        if (row == N) {
            count++;            // 找到一个合法解，计数加 1
            return;
        }
        for (int col = 0; col < N; col++) {
            // 检查列、主对角线、副对角线是否冲突
            if (colUsed[col] == 1 || diag1Used[row - col + N - 1] == 1 || diag2Used[row + col] == 1)
                continue;       // 有冲突，跳过
            // 放置皇后
            colUsed[col] = 1;
            diag1Used[row - col + N - 1] = 1;
            diag2Used[row + col] = 1;
            // 递归下一行
            backtrack(row + 1);
            // 回溯，移除皇后
            colUsed[col] = 0;
            diag1Used[row - col + N - 1] = 0;
            diag2Used[row + col] = 0;
        }
    }

    int totalNQueens(int n) {
        N = n;
        count = 0;
        colUsed = vector<int>(n, 0);
        diag1Used = vector<int>(2 * n - 1, 0);
        diag2Used = vector<int>(2 * n - 1, 0);
        backtrack(0);
        return count;
    }
};
