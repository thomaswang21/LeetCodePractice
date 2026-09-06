class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store {prefix_sum % k : index}
        unordered_map<int, int> remainderMap;
        
        // Base case: To handle valid subarrays that start from the very beginning (index 0).
        // A remainder of 0 at index -1 gives us a length of 2 if we hit a remainder of 0 at index 1.
        remainderMap[0] = -1;
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            // Calculate remainder
            int remainder = prefixSum % k;
            
            // Have we seen this remainder before?
            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Ensure the subarray length is at least 2
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                // We only store the *first* time we see a remainder.
                // We want to maximize the distance between matching remainders 
                // to ensure the length is at least 2.
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};