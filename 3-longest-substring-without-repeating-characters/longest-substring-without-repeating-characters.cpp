class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int res=0;
        unordered_map<char,int>hash;
        while(right<s.size()){
            char c=s[right];
            right++;
            hash[c]++;
            while(hash[c]>1){
                char d=s[left];
                left++;
                hash[d]--;
            }
            res=max(res,right-left);
        }
        return res;

    }
};