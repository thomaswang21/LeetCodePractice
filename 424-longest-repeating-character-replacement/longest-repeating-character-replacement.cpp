class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxd = 0;
        int res = 0;
        for(int right = 0; right < s.size(); right++){
           
            hash[s[right]]++;
            maxd = max(maxd, hash[s[right]]);
           while((right - left +1) - maxd > k){
                
                hash[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};