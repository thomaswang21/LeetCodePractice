class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_length = INT_MAX;
        int left = 0;
        int current_sum = 0;
        
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            // 当子数组的和大于等于目标值时，尝试从左侧缩小窗口
            while (current_sum >= target) {
                min_length = min(min_length, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }
        
        // 使用 if-else 替代三元运算符
        if (min_length == INT_MAX) {
            return 0;
        }
        
        return min_length;
    }
};