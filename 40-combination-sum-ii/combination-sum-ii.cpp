class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排序，便于去重
        backtrack(candidates, 0, target);
        return res;
    }

    void backtrack(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            // 跳过重复元素
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            track.push_back(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i]); // i+1，不能重复使用
            track.pop_back();
        }
    }
};
