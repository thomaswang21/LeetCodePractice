#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // 哈希表记录字符及其最后一次出现的索引
        std::unordered_map<char, int> charMap;
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // 如果哈希表中存在该字符，并且其记录的索引在当前窗口内（>= left）
            // 则将 left 指针移动到重复字符的下一个位置
            if (charMap.count(currentChar) && charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1;
            }
            
            // 更新该字符最后出现的索引为当前的 right
            charMap[currentChar] = right;
            
            // 计算当前窗口长度，并更新最大长度
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};