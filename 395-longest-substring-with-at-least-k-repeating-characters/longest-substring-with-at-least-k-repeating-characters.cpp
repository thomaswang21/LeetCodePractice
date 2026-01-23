class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int res = 0;

        // 枚举窗口中不同字符的个数
        for (int t = 1; t <= 26; t++) {
            vector<int> cnt(26, 0);
            int left = 0, right = 0;
            int unique = 0;
            int atLeastK = 0;

            while (right < n) {
                // 扩展右边界
                int r = s[right] - 'a';
                if (cnt[r] == 0) unique++;
                cnt[r]++;
                if (cnt[r] == k) atLeastK++;
                right++;

                // 如果字符种类超过 t，收缩左边界
                while (unique > t) {
                    int l = s[left] - 'a';
                    if (cnt[l] == k) atLeastK--;
                    cnt[l]--;
                    if (cnt[l] == 0) unique--;
                    left++;
                }

                // 判断是否合法窗口
                if (unique == t && unique == atLeastK) {
                    res = max(res, right - left);
                }
            }
        }
        return res;
    }
};
