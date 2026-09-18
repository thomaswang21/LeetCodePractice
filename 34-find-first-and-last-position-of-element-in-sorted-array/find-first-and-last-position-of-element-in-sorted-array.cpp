class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int first_pos = findFirst(nums, target);
        
        // 如果连第一个都没找到（越界了，或者找到的数不是 target），说明根本不存在，直接返回
        if (first_pos == nums.size() || nums[first_pos] != target) {
            return {-1, -1};
        }
        
        int last_pos = findLast(nums, target);
        
        return {first_pos, last_pos};
    }

private:
    // 第一段二分：寻找起始位置 (第一个 >= target 的位置)
    int findFirst(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] >= target) {
                // 当前数字大于等于目标值。为了找“第一个”，我们要把右边界往左压
                r = mid - 1;
            } else {
                // 当前数字太小了，左边界往右推
                l = mid + 1;
            }
        }
        // 找下限（第一个），循环结束时返回 l
        return l; 
    }

    // 第二段二分：寻找结束位置 (最后一个 <= target 的位置)
    int findLast(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] <= target) {
                // 当前数字小于等于目标值。为了找“最后一个”，我们要把左边界往右推
                l = mid + 1;
            } else {
                // 当前数字太大了，右边界往左压
                r = mid - 1;
            }
        }
        // 找上限（最后一个），循环结束时返回 r
        return r; 
    }
};