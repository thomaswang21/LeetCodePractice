class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            // 枚举长度为奇数的情况
            for (int j = i, k = i; j >= 0 && k < s.size(); j --, k ++ ) {
                if (s[j] != s[k]) break;
                res ++ ;
            }

            // 偶数情况
            for (int j = i, k = i + 1; j >= 0 && k < s.size(); j --, k ++ ) {
                if (s[j] != s[k]) break;
                res ++ ;
            }
        }
        return res;
    }
};

