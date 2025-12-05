#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> count,read;

        // 统计 s 中每个字符的频率
        for (char c : s) {
            count[c]++;
        }

        // 对 t 中的每个字符进行抵消
        for (char c : t) {
            read[c]++;
           // 若某字符数量变负，说明 t 含有多余字符
        }

        return count==read; // 所有字符都抵消完即为异位词
    }
};

