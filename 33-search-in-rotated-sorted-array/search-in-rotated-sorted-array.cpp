class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int n = nums.size();
        
        // ==========================================
        // 第一段二分：完全就是 153 题的代码，找最小值的索引
        // ==========================================
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= nums.back()) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int min_idx = l; // 最小值（悬崖）的位置
        
        // ==========================================
        // 判断 target 到底在哪一半，重置 l 和 r
        // ==========================================
        if (target <= nums.back()) {
            // target 在右半边的有序数组里
            l = min_idx;
            r = n - 1;
        } else {
            // target 在左半边的有序数组里
            l = 0;
            r = min_idx - 1;
        }
        
        // ==========================================
        // 第二段二分：最普通的标准二分查找
        // ==========================================
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};