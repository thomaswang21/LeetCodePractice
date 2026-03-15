

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq; // 记录每个数字剩余次数
        unordered_map<int, int> need; // 记录哪些数字被需要来延续序列

        // 初始化freq
        for (int num : nums) {
            freq[num]++;
        }

        // 遍历数组
        for (int num : nums) {
            if (freq[num] == 0) continue; // 当前数字已用完，跳过

            // 如果当前数字被需要来延续某个序列
            if (need[num] > 0) {
                need[num]--;       // 当前数字被使用
                need[num + 1]++;   // 下一个数字将被需要
                freq[num]--;       // 当前数字消耗一次
            }
            // 否则尝试新建一个长度≥3的序列
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num]--;
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;   // 下一个数字将被需要
            }
            // 否则无法满足条件
            else {
                return false;
            }
        }

        return true;
    }
};
