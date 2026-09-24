class Solution {
private:
    vector<int> prefixSums;
    int totalSum;

public:
    Solution(vector<int>& w) {
        totalSum = 0;
        for (int weight : w) {
            totalSum += weight;
            prefixSums.push_back(totalSum);
        }
    }
    
    int pickIndex() {
        // Generate a random number between 1 and totalSum (inclusive)
        int randNum = (rand() % totalSum) + 1;
        
        // Binary search to find the first prefix sum that is >= randNum
        auto it = lower_bound(prefixSums.begin(), prefixSums.end(), randNum);
        
        // Return the index corresponding to the segment
        return distance(prefixSums.begin(), it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */