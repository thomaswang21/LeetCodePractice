#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // 使用哈希表记录窗口内每个字符的出现次数
        std::unordered_map<char, int> countMap;
        
        int left = 0;
        int maxCount = 0; // 当前窗口内单个字符出现的最大频次
        int maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            char rightChar = s[right];
            countMap[rightChar]++;
            
            // 更新当前窗口内字符的最大频次
            maxCount = std::max(maxCount, countMap[rightChar]);

            // 如果当前窗口大小减去最多字符的频次大于 k，说明需要替换的字符过多
            // 此时需要收缩左边界
            while ((right - left + 1) - maxCount > k) {
                char leftChar = s[left];
                countMap[leftChar]--;
                left++;
            }

            // 更新最大合法窗口长度
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};