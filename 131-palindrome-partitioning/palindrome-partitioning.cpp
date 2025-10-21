class Solution {
    vector<vector<string>> res;
    vector<string> track;

public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

    // 回溯算法框架
    void backtrack(string s, int start) {
        if (start == s.length()) {
            // base case，走到叶子节点
            // 即整个 s 被成功分割为若干个回文子串，记下答案
            res.push_back(track);
        }
        for (int i = start; i < s.length(); i++) {
            if (!isPalindrome(s, start, i)) {
                // s[start..i] 不是回文串，不能分割
                continue;
            }
            // s[start..i] 是一个回文串，可以进行分割
            // 做选择，把 s[start..i] 放入路径列表中
            track.push_back(s.substr(start, i - start + 1));
            // 进入回溯树的下一层，继续切分 s[i+1..]
            backtrack(s, i + 1);
            // 撤销选择
            track.pop_back();
        }
    }

    // 用双指针技巧判断 s[lo..hi] 是否是一个回文串
    bool isPalindrome(string s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
};

