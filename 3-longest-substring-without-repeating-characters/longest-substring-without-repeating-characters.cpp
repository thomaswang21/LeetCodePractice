class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int res=0;
        unordered_map<char,int>hash;
        while(r<s.size()){
            char c=s[r];
            hash[c]++;
            r++;
            while(hash[c]>1){
                char d=s[l];
                hash[d]--;
                l++;
            }
            res=max(res, r-l);
        }
        return res;
        
    }
};