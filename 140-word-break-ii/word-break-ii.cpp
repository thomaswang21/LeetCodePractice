

class Solution {
public:
    // 主函数时间复杂度 O(n^2 * m)，空间复杂度 O(n * k)
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // 将字典放入哈希集合中，便于O(1)查找
        unordered_map<string, vector<string>> memo; // 记忆化缓存
        return dfs(s, dict, memo);
    }

private:
    // dfs函数时间复杂度 O(n^2)，空间复杂度 O(n)
    vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end()) return memo[s]; // 若已计算过，直接返回缓存结果
        vector<string> res;
        if (s.empty()) { // 若字符串为空，表示成功分割到末尾
            res.push_back("");
            return res;
        }

        // 遍历所有可能的前缀
        for (int i = 1; i <= s.size(); i++) {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end()) { // 若前缀在字典中
                string suffix = s.substr(i);
                vector<string> subRes = dfs(suffix, dict, memo); // 递归处理剩余部分
                for (string str : subRes) {
                    if (str.empty()) res.push_back(prefix); // 若剩余为空，直接加入前缀
                    else res.push_back(prefix + " " + str); // 否则拼接空格和后续部分
                }
            }
        }
        memo[s] = res; // 缓存结果
        return res;
    }
};



