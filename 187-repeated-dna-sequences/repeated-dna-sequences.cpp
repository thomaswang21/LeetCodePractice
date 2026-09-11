class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Edge case: if the string is shorter than 10 chars, no 10-letter sequences exist
        if (s.length() < 10) return {};
        
        unordered_set<string> seen;
        unordered_set<string> repeated;
        
        // Slide a window of exactly length 10 across the string
        for (int i = 0; i <= s.length() - 9 ; i++) {
            string current_seq = s.substr(i, 10);
            
            // If it's already in 'seen', we found a duplicate
            if (seen.count(current_seq)) {
                repeated.insert(current_seq);
            } else {
                seen.insert(current_seq);
            }
        }
        
        // Return the collected repeated sequences as a vector
        return vector<string>(repeated.begin(), repeated.end());
    }
};