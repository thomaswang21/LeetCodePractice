class Solution {
public:
    // 记录所有全排列
    vector<vector<int>> res;
    // 记录当前正在穷举的排列
    vector<int> track;

    // track 中的元素会被标记为 true，避免重复使用
    vector<bool> used;

    // 主函数，输入一组不重复的数字，返回它们的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        
        backtrack(nums);
        return res;
    }

    // 回溯算法核心框架，遍历回溯树，收集所有叶子节点上的全排列
    void backtrack(vector<int>& nums) {
        // 到达叶子节点，track 中的元素就是一个全排列
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // 排除不合法的选择
            if (used[i]) {
                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;

            // 进入递归树的下一层
            backtrack(nums);
            
            // 取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};