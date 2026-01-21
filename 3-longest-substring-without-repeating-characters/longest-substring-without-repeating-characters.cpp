class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>charIndex;
        int n=s.length();
        int left=0;
        int right;
        int max_len=0;
        for(right=0;right<n;right++){
            char currentChar=s[right];
            if(charIndex.count(currentChar)){
                left=max(left,charIndex[currentChar]+1);

            }
            charIndex[currentChar]=right;
            max_len=max(max_len, right-left+1);
        }
        return max_len;

    }
};