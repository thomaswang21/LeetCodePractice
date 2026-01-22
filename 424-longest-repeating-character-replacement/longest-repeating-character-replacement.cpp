class Solution {
public:
    int characterReplacement(string s, int k) {
        // 使用哈希表代替 vector
        unordered_map<char, int> map;
        int left = 0;
        int maxCount = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            // 1. 进窗口：记录字符频率
            map[s[right]]++;
            
            // 更新当前窗口内出现次数最多的字符数量
            maxCount = max(maxCount, map[s[right]]);

            // 2. 出窗口：判断是否需要缩小窗口
            // 窗口总长度 - 主字符数量 > k，说明要把其他字符变为主字符需要的操作超过了 k
            while ((right - left + 1) - maxCount > k) {
                map[s[left]]--; // 移出左边的字符
                left++;
            }

            // 3. 更新结果
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};