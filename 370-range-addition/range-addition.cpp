class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // Initialize vector with 0s
        vector<int> res(length, 0);

        // Step 1: Apply the Difference Array logic
        for (const auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int val = update[2];

            // Apply increment at the start index
            res[start] += val;

            // Apply decrement at (end + 1) index to cancel the effect for subsequent elements
            // We must check if (end + 1) is within the array bounds
            if (end + 1 < length) {
                res[end + 1] -= val;
            }
        }

        // Step 2: Compute Prefix Sums to apply the changes across the ranges
        for (int i = 1; i < length; ++i) {
            res[i] += res[i - 1];
        }

        return res;
    }
};