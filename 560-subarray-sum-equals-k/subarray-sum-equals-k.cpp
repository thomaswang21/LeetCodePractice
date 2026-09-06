#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store the frequency of prefix sums
        unordered_map<int, int> prefix_counts;
        
        // Base case: a prefix sum of 0 has occurred exactly once (an empty prefix)
        prefix_counts[0] = 1;
        
        int count = 0;
        int curr_sum = 0;
        
        for (int num : nums) {
            curr_sum += num;
            
            // If (curr_sum - k) exists, it means we found subarray(s) summing to k
            if (prefix_counts.find(curr_sum - k) != prefix_counts.end()) {
                count += prefix_counts[curr_sum - k];
            }
            
            // Add the current prefix sum to our map for future calculations
            prefix_counts[curr_sum]++;
        }
        
        return count;
    }
};