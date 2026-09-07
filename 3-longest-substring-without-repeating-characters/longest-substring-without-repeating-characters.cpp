class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++){
            char current = s[right];
            if(hash.count(current) && hash[current] >= left){
                left = hash[current] + 1;
            }
            hash[current] = right;
            maxLength = max(maxLength, right - left +1);

        }
        return maxLength;
    }
};