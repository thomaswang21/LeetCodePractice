class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排序便于去重
        backtrack(candidates, 0, target, 0);        // 传入 sum 参数
        return res;
    }

    void backtrack(vector<int>& candidates, int start, int target, int sum) {
        if (sum == target) {
            res.push_back(track);
            return;
        }
        if (sum > target) return;

        for (int i = start; i < candidates.size(); i++) {
            // 去重：同一层递归跳过重复元素
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            track.push_back(candidates[i]);
            sum += candidates[i];

            // 每个元素只能用一次，所以下一层用 i+1
            backtrack(candidates, i + 1, target, sum);

            sum -= candidates[i]; // 撤销选择
            track.pop_back();
        }
    }
};

