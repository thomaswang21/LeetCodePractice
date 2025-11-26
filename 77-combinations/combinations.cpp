class Solution {
public:
    vector<vector<int>> res;   // 记录所有结果
    vector<int> track;         // 当前路径

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }

    // 从 start 开始选，目标是选 k 个
    void backtrack(int start, int n, int k) {
        // 终止条件：track 已经选够 k 个数
        if (track.size() == k) {
            res.push_back(track);
            return;
        }

        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            // 递归进入下一层
            backtrack(i + 1, n, k);
            // 撤销选择
            track.pop_back();
        }
    }
};
