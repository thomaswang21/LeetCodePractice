class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> countMap;
        int left = 0;
        int maxCount = 0;
        int maxLength = 0;
        
        for(int right = 0; right < s.size(); right++){
            char rightChar = s[right];
            countMap[rightChar]++;
            maxCount = max(maxCount, countMap[rightChar]);

            while((right - left +1 ) - maxCount > k){
                char leftChar = s[left];
                countMap[leftChar]--;
                left++;
            }
            maxLength = max(maxLength, right - left +1);
        }
        return maxLength;
    }
};