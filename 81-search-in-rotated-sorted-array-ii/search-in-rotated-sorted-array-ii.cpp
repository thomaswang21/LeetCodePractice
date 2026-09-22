class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        
        // 提前查一下车头。因为后面我们要把和车头相同的车尾砍掉，
        // 万一 target 刚好就是车头这个数字，先 check 一下最保险。
        if (nums[0] == target) return true;
        
        int n = nums.size();
        
        // ==========================================
        // 第 0 步：恢复二段性 (唯一新加的代码)
        // 忽略尾部所有和 nums[0] 相同的元素
        // ==========================================
        int right_bound = n - 1;
        while (right_bound > 0 && nums[right_bound] == nums[0]) {
            right_bound--;
        }
        
        // ==========================================
        // 第一段二分：找最小值的索引 (拿砍完尾巴后的 right_bound 做标杆)
        // ==========================================
        int l = 0, r = right_bound;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= nums[right_bound]) { // 注意这里不再是 nums.back()
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int min_idx = l; // 最小值（悬崖）的位置
        
        // ==========================================
        // 判断 target 到底在哪一半，重置 l 和 r
        // ==========================================
        if (target <= nums[right_bound]) { // 同样，用 right_bound 比较
            // target 在右半边的有序数组里
            l = min_idx;
            r = right_bound;
        } else {
            // target 在左半边的有序数组里
            l = 0;
            r = min_idx - 1;
        }
        
        // ==========================================
        // 第二段二分：最普通的标准二分查找 (完全没变)
        // ==========================================
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true; // 题目要求返回 bool
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false; // 没找到返回 false
    }
};