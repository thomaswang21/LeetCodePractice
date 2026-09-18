class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 运气好，直接找到了
            if (nums[mid] == target) {
                return mid;
            }
            
            // 核心逻辑开始：判断哪一半是有序的
            // 如果 nums[l] <= nums[mid]，说明从 l 到 mid 这一段没有悬崖，是完全升序的
            if (nums[l] <= nums[mid]) {
                
                // 既然左半边是有序的，我们就能确定 target 在不在里面
                if (nums[l] <= target && target < nums[mid]) {
                    // target 在这个有序的左半边范围内，所以丢弃右半边
                    r = mid - 1;
                } else {
                    // target 不在左半边，那只能去右半边找了
                    l = mid + 1;
                }
                
            } 
            // 否则，说明悬崖在左半边，那么右半边 (mid 到 r) 必定是完全升序的
            else {
                
                // 既然右半边是有序的，我们判断 target 在不在右半边
                if (nums[mid] < target && target <= nums[r]) {
                    // target 在这个有序的右半边范围内，所以丢弃左半边
                    l = mid + 1;
                } else {
                    // target 不在右半边，那只能去左半边找了
                    r = mid - 1;
                }
                
            }
        }
        
        // 循环结束都没找到，说明 target 根本不在数组里
        return -1;
    }
};