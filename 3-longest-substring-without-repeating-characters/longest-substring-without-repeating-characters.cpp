class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        // Key: character, Value: index
        unordered_map<char, int> charIndexMap;
        
        int maxLength = 0;
        int left = 0;
        
        // Iterate through the string with the 'right' pointer
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If character is found in map and is inside the current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && 
                charIndexMap[currentChar] >= left) {
                // Move the left pointer to the right of the previous occurrence
                left = charIndexMap[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndexMap[currentChar] = right;
            
            // Calculate current window length and update max
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};