class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // If s1 is longer than s2, it cannot be a substring
        if (n > m) return false;
        
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // 1. Compute frequency for s1 and the first window of s2
        for (int i = 0; i < n; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        // Check the first window immediately
        if (s1_count == window_count) return true;
        
        // 2. Slide the window across s2
        for (int i = n; i < m; i++) {
            // Add the new character entering the window (right side)
            window_count[s2[i] - 'a']++;
            
            // Remove the character leaving the window (left side)
            window_count[s2[i - n] - 'a']--;
            
            // Compare the frequency maps
            if (s1_count == window_count) return true;
        }
        
        return false;
    }
};