class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLength = INT_MAX; // 初始化为一个最大整数，表示还没找到

        for (int right = 0; right < nums.size(); ++right) {
            // 1. 进窗口
            currentSum += nums[right];

            // 2. 满足条件时，尝试缩小窗口
            while (currentSum >= target) {
                // 更新最小长度
                int currentLen = right - left + 1;
                if (currentLen < minLength) {
                    minLength = currentLen;
                }
                
                // 出窗口
                currentSum -= nums[left];
                left++;
            }
        }

        // 如果 minLength 还是初始值，说明没找到任何符合条件的子数组
        if (minLength == INT_MAX) {
            return 0;
        }
        
        return minLength;
    }
};