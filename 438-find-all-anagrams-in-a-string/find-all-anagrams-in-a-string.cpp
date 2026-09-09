class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        // 注意：这里比较的是长度，而不是直接用 s > p 比较字典序
        if(p.size() > s.size()){
            return res;
        }
        
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        
        // 必须先把目标字符串 p 的字符频次存入 need
        for(char c : p){
            need[c]++;
        }
        
        int left = 0;
        int right = 0;
        int valid = 0;
        
        while(right < s.size()){
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            
            // 当窗口大小大于等于 p 的长度时，说明需要收缩窗口了
            while(right - left >= p.size()){
                // 窗口内的字符完全匹配 p 的字符频次
                if(valid == need.size()){
                    // 这里不直接 return true，而是把起点索引加入结果数组
                    res.push_back(left); 
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};