class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = -1;
        
        int max_val = nums[0];
        int min_val = nums[n - 1];
        
        // Find the rightmost element that is smaller than the max seen so far
        for (int i = 1; i < n; i++) {
            max_val = max(max_val, nums[i]);
            if (nums[i] < max_val) {
                high = i;
            }
        }
        
        // Find the leftmost element that is larger than the min seen so far
        for (int i = n - 2; i >= 0; i--) {
            min_val = min(min_val, nums[i]);
            if (nums[i] > min_val) {
                low = i;
            }
        }
        
        return high - low + 1;
    }
};