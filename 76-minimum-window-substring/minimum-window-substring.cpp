#include <unordered_map>
#include <string>

using namespace std;

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

        // 把 right 的初始化放进 for 循环里
        int left = 0;
        int valid = 0;         // 记录当前窗口中，已经满足数量要求的字符种类数
        int min_len = INT_MAX;     // 记录最小窗口长度
        int min_start = 0;     // 记录最小窗口的起始索引

        // 最外层 while 换成 for
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            // 如果该字符是我们需要匹配的字符
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 当 valid 等于 need 的大小，说明所有需要的字符及其数量都已经满足
            while (valid == need.size()) {
                
                // 【关键改变】因为 right 没有提前 ++，当前包含所有元素的闭区间是 [left, right]
                // 所以当前窗口的长度是 right - left + 1
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1; // 更新最新长度也要加 1
                    min_start = left;
                }

                char d = s[left];
                left++; // 缩小窗口
                
                // 如果移出的字符是我们目标 t 中的字符
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        if (min_len == INT_MAX) {
            return "";
        }
        
        return s.substr(min_start, min_len);
    }
};