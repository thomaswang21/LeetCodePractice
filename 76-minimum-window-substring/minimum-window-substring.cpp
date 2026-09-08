#include <unordered_map>
#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::unordered_map<char, int> need;
        std::unordered_map<char, int> window;
        
        // 统计字符串 t 中每个字符需要的数量
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;         // 记录当前窗口中，已经满足数量要求的字符种类数
        int min_len = 1e9;     // 记录最小窗口长度
        int min_start = 0;     // 记录最小窗口的起始索引

        while (right < s.length()) {
            char c = s[right];
            right++; // 扩大窗口
            
            // 如果该字符是我们需要匹配的字符
            if (need.count(c)) {
                window[c]++;
                // 当窗口中该字符的数量达到了需要的数量，满足条件的字符种类数 +1
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 当 valid 等于 need 的大小，说明所有需要的字符及其数量都已经满足
            while (valid == need.size()) {
                // 更新最小窗口的数据
                if (right - left < min_len) {
                    min_len = right - left;
                    min_start = left;
                }

                char d = s[left];
                left++; // 缩小窗口
                
                // 如果移出的字符是我们目标 t 中的字符
                if (need.count(d)) {
                    // 如果移出后，数量不再满足要求，满足条件的字符种类数 -1
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        // 不使用三元运算符，使用普通的 if 判断返回结果
        if (min_len == 1e9) {
            return "";
        }
        
        return s.substr(min_start, min_len);
    }
};