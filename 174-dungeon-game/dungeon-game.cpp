#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // Pad the DP table with an extra row and column, initialized to infinity
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        // Base case: The knight needs at least 1 health immediately after rescuing the princess.
        // We place these 1s just outside the bottom-right cell to cleanly trigger the DP logic.
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        
        // Traverse backwards from the bottom-right corner to the top-left corner
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // The minimum health required to survive moving to the next optimal room
                int minHealthOnExit = min(dp[i + 1][j], dp[i][j + 1]);
                
                // Calculate health needed BEFORE entering this room.
                // If a magic orb (positive number) heals us more than we need for the rest 
                // of the journey, it might result in a negative requirement. We cap the minimum at 1.
                dp[i][j] = max(1, minHealthOnExit - dungeon[i][j]);
            }
        }
        
        // The result is the minimum initial health required at the starting room
        return dp[0][0];
    }
};