

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // 初始化频率数组
        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // 判断初始窗口
        if (count1 == count2) return true;

        // 滑动窗口
        for (int i = len1; i < len2; i++) {
            count2[s2[i] - 'a']++;           // 加入新字符
            count2[s2[i - len1] - 'a']--;    // 移除旧字符
            if (count1 == count2) return true;
        }

        return false;
    }
};

