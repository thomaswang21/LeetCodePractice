class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // Initialize the answer array with zeros. 
        // Size n is enough because we'll handle the out-of-bounds check for `last + 1`.
        vector<int> answer(n, 0);
        
        // Step 1: Mark the start and end of each booking interval
        for (const auto& booking : bookings) {
            int first = booking[0] - 1; // Convert 1-based to 0-based index
            int last = booking[1] - 1;
            int seats = booking[2];
            
            answer[first] += seats;
            if (last + 1 < n) {
                answer[last + 1] -= seats;
            }
        }
        
        // Step 2: Compute the prefix sum to get the actual seat counts
        for (int i = 1; i < n; ++i) {
            answer[i] += answer[i - 1];
        }
        
        return answer;
    }
};
