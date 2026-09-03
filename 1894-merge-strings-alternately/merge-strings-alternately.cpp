class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string s = "";
        
        // 阶段 1：只要两个字符串都还没遍历完，就交替添加
        while (i < word1.size() && j < word2.size()) {
            s += word1[i];
            i++;
            s += word2[j];
            j++;
        }
        
        // 阶段 2：如果 word1 还有剩下的，一口气加完
        while (i < word1.size()) {
            s += word1[i];
            i++;
        }
        
        // 阶段 3：如果 word2 还有剩下的，一口气加完
        while (j < word2.size()) {
            s += word2[j];
            j++;
        }
        
        return s;
    }
};