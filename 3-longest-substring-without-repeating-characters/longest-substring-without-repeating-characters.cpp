class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++){
            while(hash.count(s[right]) && hash[s[right]] >= left){
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right;
            maxLength = max(maxLength, right - left +1);

        }
        return maxLength;
    }
};