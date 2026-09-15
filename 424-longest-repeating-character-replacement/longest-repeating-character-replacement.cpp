class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxd = 0;
        int res = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            hash[c]++;
            maxd = max(maxd, hash[c]);
            while((right - left +1) - maxd > k){
                char l = s[left];
                hash[l]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};