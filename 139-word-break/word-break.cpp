

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将字典放入哈希表，方便 O(1) 查询
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]); // 插入字典单词
        }

        int n = s.size();
        vector<bool> dp(n + 1, false); // dp[i] 表示前 i 个字符是否可拆分
        dp[0] = true; // 空字符串可被拆分

        // 遍历字符串
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // 如果前 j 个能拆分，且 s[j..i-1] 在字典中
                if (dp[j]) {
                    string word = s.substr(j, i - j); // 取子串
                    if (dict.find(word) != dict.end()) {
                        dp[i] = true; // 前 i 个字符可拆分
                        break; // 提前结束，减少无效判断
                    }
                }
            }
        }

        return dp[n]; // 返回结果
    }
};
