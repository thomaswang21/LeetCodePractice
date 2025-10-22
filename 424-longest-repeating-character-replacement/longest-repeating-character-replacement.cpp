class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>hash;
        int l=0, r=0;
        int res=0;
        int maxhash=0;
        while(r<s.length()){
            char c=s[r];
            r++;
            hash[c]++;
            
            maxhash=max(maxhash,hash[c]);
            while(r-l-maxhash>k){
                char d=s[l];
                hash[d]--;
                l++;
            }
            res=max(res, r-l);
        }
        return res;
    }
};