#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Use a set for O(1) average time complexity lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        
        // dp[i] represents if s.substr(0, i) can be segmented
        // Size is n + 1 to accommodate the empty string (dp[0])
        vector<bool> dp(n + 1, false);
        
        // Base case: empty string is valid
        dp[0] = true;
        
        // Iterate through the string length i
        for (int i = 1; i <= n; ++i) {
            // Iterate through all possible previous split points j
            for (int j = 0; j < i; ++j) {
                
                // If the first part (0 to j) is valid 
                // AND the substring from j to i is in the dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // No need to check other j's if we found a valid path
                }
            }
        }
        
        return dp[n];
    }
};