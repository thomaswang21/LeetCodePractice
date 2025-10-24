class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // 最小值一定在 mid 右边
                left = mid + 1;
            } else {
                // 最小值在 mid 左边或就是 mid
                right = mid;
            }
        }
        // 最终 left == right 指向最小值
        return nums[right];
    }
};
