class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++){
            // 发现重复字符，且该字符在当前窗口内，才更新 left
            while(hash.count(s[right]) && hash[s[right]] >= left){
                left = hash[s[right]] + 1;
            }
            hash[s[right]] = right; // 更新字符最新的下标
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};