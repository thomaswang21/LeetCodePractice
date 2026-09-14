class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> countMap;
        int maxd = 0;
        int res = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            countMap[c]++;
            maxd = max(maxd, countMap[c]);
            while((right - left +1) - maxd > k){
                char l = s[left];
                countMap[l]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};