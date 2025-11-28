class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int len : matchsticks) sum += len;
        if (sum % 4 != 0) return false; // 总长度不能被4整除
        
        int target = sum / 4;
        vector<int> sides(4, 0); // 存四条边的长度
        
        // 可以先排序火柴，长的先用 → 提前剪枝
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        return backtrack(matchsticks, sides, 0, target);
    }

    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int target) {
        if (index == matchsticks.size()) {
            // 所有火柴放完，检查四条边是否都等于 target
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] > target) continue; // 剪枝
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, sides, index + 1, target)) return true;
            sides[i] -= matchsticks[index]; // 回溯
        }

        return false;
    }
};

