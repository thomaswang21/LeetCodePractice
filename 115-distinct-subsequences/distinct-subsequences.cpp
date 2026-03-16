class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // A smaller string cannot contain a larger one as a subsequence
        if (m < n) return 0;
        
        // dp[j] will store the number of ways to form the prefix t[0...j-1].
        // We use unsigned long long because intermediate DP calculations 
        // can sometimes exceed the 32-bit integer limit, even if the final answer fits.
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: an empty string `t` can be formed exactly 1 way 
        // (by deleting all characters from `s`).
        dp[0] = 1;
        
        for (int i = 1; i <= m; ++i) {
            // We iterate backwards from n down to 1.
            // This prevents us from using the newly updated dp[j-1] from the 
            // CURRENT row `i`; we want the value from the PREVIOUS row `i-1`.
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        // Cast back to int as the problem guarantees the final answer fits in 32-bit
        return static_cast<int>(dp[n]); 
    }
};