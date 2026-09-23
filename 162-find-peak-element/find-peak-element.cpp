class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        // 這裡使用 l < r，當 l == r 時，我們就找到唯一的山峰了
        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // 下坡：代表山峰在左邊，或者 mid 本身就是山峰
                r = mid;
            } else {
                // 上坡：代表山峰一定在右邊 (mid 絕對不會是山峰，所以 +1)
                l = mid + 1;
            }
        }
        
        // 迴圈結束時，l 和 r 會重疊，停留在山峰的索引上
        return l; 
    }
};