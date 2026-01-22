class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // 1. Expand window: If we see a zero, increment our counter
            if (nums[right] == 0) {
                zeroCount++;
            }

            // 2. Shrink window: If zeros exceed k, move left pointer
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // 3. Update result: current window size is valid
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};