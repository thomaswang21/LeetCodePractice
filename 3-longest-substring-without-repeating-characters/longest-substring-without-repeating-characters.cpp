class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int>hash;
        int maxL = 0;
        for(int right = 0; right < s.size(); right++){
            if(hash.count(s[right]) && hash[s[right]] >= left){
                left = hash[s[right]] +1;
            }
            hash[s[right]] = right;
        maxL = max(maxL, right - left +1 );
        }
        return maxL;
    }
};