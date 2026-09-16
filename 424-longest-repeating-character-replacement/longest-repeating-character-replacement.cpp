class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int left = 0;
        int maxc = 0;
        int maxp = 0;
        for(int right = 0; right < s.size(); right++){
            hash[s[right]]++;
            maxc = max(maxc, hash[s[right]]);
            while(right - left + 1 - maxc >k){
                hash[s[left]]--;
                left++;
            }
            maxp = max(maxp, right -left +1);
        }
        return maxp;
    }
};