class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int target = total_sum - x;
        int n = nums.size();
        
        // 如果目标和小于0，说明数组所有元素之和都小于x，不可能实现
        if (target < 0) return -1;
        // 如果目标和刚好等于0，说明要把数组全删了
        if (target == 0) return n;
        
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        
        // 滑动窗口寻找和为 target 的最长连续子数组
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            // 窗口总和超了，左边界收缩
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // 找到符合条件的子数组，更新最大长度
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // 如果 max_len 没变过，说明找不到，返回 -1；否则返回 n - max_len
        return max_len == -1 ? -1 : n - max_len;
    }
};