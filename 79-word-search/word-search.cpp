#include <vector>
#include <string>
using namespace std;

class Solution {
    bool found = false;

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, word, 0);
                if (found) return true;
            }
        }
        return false;
    }

    // 从 (i, j) 开始向四周搜索，匹配 word[track..]
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int track) {
        if (track == word.length()) {
            // 整个 word 已经匹配完
            found = true;
            return;
        }
        if (found) return; // 已找到结果，提前返回

        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) return; // 越界
        if (board[i][j] != word[track]) return;         // 字符不匹配

        // 标记已访问，避免回头
        char tmp = board[i][j];
        board[i][j] = '#';

        // 向四个方向递归搜索
        dfs(board, i + 1, j, word, track + 1);
        dfs(board, i - 1, j, word, track + 1);
        dfs(board, i, j + 1, word, track + 1);
        dfs(board, i, j - 1, word, track + 1);

        // 回溯，恢复原字符
        board[i][j] = tmp;
    }
};




