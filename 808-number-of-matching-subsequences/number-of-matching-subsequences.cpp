#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // 記錄 s 中每個字元出現的所有索引位置
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < s.length(); ++i) {
            pos[s[i]].push_back(i);
        }
        
        int count = 0;
        
        // 檢查每個 word
        for (const string& word : words) {
            int curr_idx = -1; // 記錄上一個配對成功的字元在 s 中的位置
            bool is_subsequence = true;
            
            for (char c : word) {
                // 如果 s 中根本沒有這個字元，直接失敗
                if (pos.find(c) == pos.end()) {
                    is_subsequence = false;
                    break;
                }
                
                // 使用二分搜尋法找 pos[c] 中，第一個大於 curr_idx 的位置
                auto it = upper_bound(pos[c].begin(), pos[c].end(), curr_idx);
                
                // 如果找不到更大的索引位置，代表順序不對或字元用光了
                if (it == pos[c].end()) {
                    is_subsequence = false;
                    break;
                }
                
                // 更新當前的位置為找到的索引
                curr_idx = *it;
            }
            
            // 如果全部字元都配對成功
            if (is_subsequence) {
                count++;
            }
        }
        
        return count;
    }
};