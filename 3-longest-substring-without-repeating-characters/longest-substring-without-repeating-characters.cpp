class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>last;
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            if(last.count(c) && last[c] >= left){
                left = last[c] + 1;

            }
            last[c] = right;
            ans = max(ans, right - left +1);
        }
        return ans;
    }
};