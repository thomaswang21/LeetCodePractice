class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string>& x, const pair<int, string>& y) {
            // 频率小的优先级低（大顶堆）
            if (x.first == y.first) {
                // 频率相同，字典序小的优先级高
                return x.second > y.second;
            }
            return x.first < y.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> M;  // 改这里
        
        // 统计频率
        for (const string& word : words) {
            M[word]++;
        }

        // 大顶堆
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        // 把 (频率, 单词) 放进堆
        for (auto& it : M) {
            pq.push({it.second, it.first});
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
