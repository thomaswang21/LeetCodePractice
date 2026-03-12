

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 按宽度升序，高度降序排序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // 构建高度序列
        vector<int> heights;
        for (int i = 0; i < envelopes.size(); i++) {
            heights.push_back(envelopes[i][1]);
        }

        // 寻找高度的最长递增子序列
        vector<int> lis;
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};
