class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Array to store the net change in passengers at each kilometer mark.
        // Assuming the max location constraint is 1000. 
        vector<int> stops(1001, 0);
        
        // Record the passenger changes for each trip
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            stops[from] += numPassengers; // Passengers get on
            stops[to] -= numPassengers;   // Passengers get off
        }
        
        // Sweep across the route to track current capacity
        int currentPassengers = 0;
        for (int i = 0; i <= 1000; ++i) {
            currentPassengers += stops[i];
            
            if (currentPassengers > capacity) {
                return false;
            }
        }
        
        return true;
    }
};