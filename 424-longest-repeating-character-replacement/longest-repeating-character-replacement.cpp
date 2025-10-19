class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int windowMaxCount = 0;
        int res = 0;

        while (right < s.length()) {
            char c = s[right];
             right++;
            window[c]++;
            windowMaxCount = max(windowMaxCount, window[c]);
           

            // 替换成本太高，窗口不合法，收缩
            while (right - left - windowMaxCount > k) {
                window[s[left]]--;
                left++;
            }

            res = max(res, right - left);
        }

        return res;
    }
};
