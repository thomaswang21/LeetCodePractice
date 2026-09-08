class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        
        // 1. 统计 s1 中每个字符的需求量
        for (char c : s1) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0; // 记录窗口中满足 need 条件的字符种类数

        // 2. 扩大窗口：right 指针主动向右滑动
        while (right < s2.size()) {
            char c = s2[right];
            right++; // 扩大窗口
            
            // 如果加入的字符是 s1 中需要的
            if (need.count(c)) {
                window[c]++;
                // 如果该字符在窗口中的数量达到了需要的数量，匹配的种类数 +1
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 3. 收缩窗口：当窗口长度达到 s1 的长度时，说明需要开始收缩了
            while (right - left >= s1.size()) {
                // 如果匹配的字符种类数和 need 中的种类数相等，说明找到了一个排列
                if (valid == need.size()) {
                    return true;
                }

                char d = s2[left];
                left++; // 缩小窗口

                // 如果移出的字符是 s1 中需要的
                if (need.count(d)) {
                    // 如果该字符在窗口中的数量原本是完美匹配的，移出后就不匹配了，valid -1
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return false;
    }
};