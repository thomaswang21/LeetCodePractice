class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        // 拿数组最后一个元素作为判断标杆
        int target = nums.back(); 
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 判断当前元素是否踩进了“右半边小数区”（达标区）
            if (nums[mid] <= target) {
                // 虽然当前数字达标了，但左边可能还有更小的合法元素
                // 所以我们收缩右边界，把它往左边逼
                r = mid - 1; 
            } else {
                // 当前数字比标杆还大，说明它在“左半边大数区”（失败区）
                // 最小值一定在右边，所以左边界右移
                l = mid + 1; 
            }
        }
        
        // 循环结束时，根据我们的推演，l 一定会停在“第一个达标”的位置
        // 也就是“右半边小数区”的第一个元素，即整个数组的最小值！
        return nums[l];
    }
};