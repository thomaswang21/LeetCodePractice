class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0;
        int res=0;
        int maxNum=0;
        unordered_map<char,int>hash;
        while(right<s.size()){
            char c=s[right];
            hash[c]++;
            right++;
            maxNum=max(maxNum, hash[c]);
            while(right-left-maxNum>k){
                    char d=s[left];
                    hash[d]--;
                    left++;
            }
            res=max(res,right-left);
        }
        return res;

    }
};