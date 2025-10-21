class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return res;
        }
        backtrack(candidates, 0, target, 0);
        return res;
    }

    // 记录回溯的路径
    vector<int> track;

    // 回溯算法主函数
    void backtrack(vector<int>& candidates, int start, int target, int sum) {
        if (sum == target) {
            // 找到目标和
            res.push_back(track);
            return;
        }

        if (sum > target) {
            // 超过目标和，直接结束
            return;
        }

        // 回溯算法框架
        for (int i = start; i < candidates.size(); i++) {
            // 选择 candidates[i]
            track.push_back(candidates[i]);
            sum += candidates[i];
            // 递归遍历下一层回溯树
            backtrack(candidates, i, target, sum);
            // 撤销选择 candidates[i]
            sum -= candidates[i];
            track.pop_back();
        }
    }
};