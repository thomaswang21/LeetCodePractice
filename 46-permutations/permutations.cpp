#include <vector>
#include <list>
using namespace std;

class Solution {
    vector<vector<int>> res; // 存放结果

public:
    // 主函数：输入一组不重复的数字，返回它们的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track; // 记录「路径」
        vector<bool> used(nums.size(), false); // 记录哪些元素已经使用过

        backtrack(nums, track, used);
        return res;
    }

private:
    // 路径：track
    // 选择列表：nums 中未被使用的数字
    // 结束条件：track 的长度等于 nums 的长度
    void backtrack(const vector<int>& nums, vector<int>& track, vector<bool>& used) {
        if (track.size() == nums.size()) {
            res.push_back(track); // 找到一个全排列
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // 跳过已使用的数字

            // 做选择
            track.push_back(nums[i]);
            used[i] = true;

            // 进入下一层决策树
            backtrack(nums, track, used);

            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};
