class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // 使用普通的 set 即可，内部是有序的（基于红黑树实现）
        set<long long> window;
        
        for (int i = 0; i < nums.size(); i++) {
            long long current = nums[i];
            
            // 1. 查找窗口中是否存在 >= current - t 的最小数字
            // lower_bound 可以在 O(log K) 时间内找到大于等于目标值的第一个元素
            auto it = window.lower_bound(current - t);
            
            // 2. 如果找到了，并且这个数字 <= current + t，说明差值在 t 以内，成功！
            if (it != window.end() && *it <= current + t) {
                return true;
            }
            
            // 3. 将当前数字加入滑动窗口
            window.insert(current);
            
            // 4. 维护滑动窗口的大小不超过 k
            if (window.size() > k) {
                // 删除最早进入窗口的元素
                window.erase(nums[i - k]); 
            }
        }
        
        return false;
    }
};