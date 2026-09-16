class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 修正 1：应该比较字符串长度，而不是字典序
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> need;
        unordered_map<char, int> window;
        
        // 修正 2：需要先初始化 need 哈希表，统计 s1 中各字符的数量
        for (char c : s1) {
            need[c]++;
        }

        int left = 0;
        int valid = 0;

        // 将最外层的 while 替换为了 for
        for (int right = 0; right < s2.size(); right++) {
            char c = s2[right];
            
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // 判断左侧窗口是否要收缩
            // 注意：因为 right 没有提前自增，现在的窗口长度是 right - left + 1
            while (right - left + 1 >= s1.size()) {
                // 如果满足条件，说明找到了一个排列
                if (valid == need.size()) {
                    return true;
                }
                
                char d = s2[left];
                left++; // 缩小窗口
                
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
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