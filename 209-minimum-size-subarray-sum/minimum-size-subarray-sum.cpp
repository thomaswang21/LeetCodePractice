class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        // 维护窗口内元素之和
        int windowSum = 0;
        int res = INT_MAX;

        while (right < nums.size()) {
            // 扩大窗口
            windowSum += nums[right];
            right++;
            while (windowSum >= target && left < right) {
                // 已经达到 target，缩小窗口，同时更新答案
                res = min(res, right - left);
                windowSum -= nums[left];
                left++;
            }
        }
        if (res == INT_MAX) {
    return 0;
}
return res;

    }
};