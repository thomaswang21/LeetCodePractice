#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        // Hash map to store the frequency of each remainder
        std::unordered_map<int, int> remainderFreq;
        
        // Base case: A prefix sum that is perfectly divisible by k 
        // has a remainder of 0.
        remainderFreq[0] = 1; 
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Calculate the positive remainder
            int remainder = ((prefixSum % k) + k) % k;
            
            // If this remainder exists in the map, add its frequency to the count
            if (remainderFreq.find(remainder) != remainderFreq.end()) {
                count += remainderFreq[remainder];
            }
            
            // Record the current remainder frequency
            remainderFreq[remainder]++;
        }
        
        return count;
    }
};