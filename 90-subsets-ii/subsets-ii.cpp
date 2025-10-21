class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 排序方便去重
        backtrack(nums, 0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int start) {
        // 前序位置：每个节点的 track 都是一个子集
        res.push_back(track);

        for (int i = start; i < nums.size(); i++) {
            // 去重：同一层递归跳过重复元素
            if (i > start && nums[i] == nums[i - 1]) continue;

            track.push_back(nums[i]);        // 选择当前元素
            backtrack(nums, i + 1);          // 下一层从 i+1 开始
            track.pop_back();                // 撤销选择
        }
    }
};
